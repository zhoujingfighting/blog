## 实现用户的登陆验证
今天主要是做了一个小练习，使用Express做了一个简单的注册，登陆与验证。

技术库的选择：

nodejs ： express框架
jwt验证 ： jsonwebtoken
数据库 ： mongoose
vscode 插件： rest-client(模拟网络请求的)
只有两个js文件，一个用来写服务器，一个用来存数据库

首先写server端的js代码

```js
const express = require('express');
const { User } = require('./mongose.js')
const app = express();
app.use(express.json())
app.get('/api', async(req, res) => {
    res.send('it is ok')
})
app.get('/api/users', async(req, res) => {
    const users = await User.find();
    res.send(users);
})
app.post('/api/register', async(req,res) => {
    const user = await User.create({
        username:req.body.username,
        password:req.body.password
    })
})
app.post('/api/login', async(req,res)=>{
    const user = await User.findOne({
        username: req.body.username
    })
    if(!user){
        res.status(422).send({
            message: '用户名不存在'
        });
    }
    const isValidPassWord = await require('bcrypt').compare(
        req.body.password,
        user.password
    )
    if(!isValidPassWord){
        return res.status(422).send({
            message: '111用户名不存在'
        });
    }
    //生成token,使用用户id
    const jwt = require('jsonwebtoken')
    const token = jwt.sign({
        id: String(user.id)
    }, 'express-auth')
    //secret should be personal
    res.send({
        user,
        token
    })
    //怎么用token
})
/**
 * 封装中间件，express的中间件就是函数
 */
const profileUser = async(req,res, next) => {
    const id = String(req.headers.authorization.split(' ').pop())
    console.log(id)
    /**
     * 不能明文存密码于token中
     */
    const tokenData = require('jsonwebtoken').verify(id, 'express-auth')
    console.log(tokenData)
    req.user = await User.findById(tokenData.id);
    /**
     * 执行完这个中间件，继续后面的
     */
    next()
}
app.get('/api/profile', profileUser, async(req, res) => {
    res.send(req.user)
})
app.listen(3001, () => {
    console.log('http://localhost:3001')
})
```
需要注意的点 ：

express的中间件很好用，一个中间件执行完，可以传到下一个
密码等核心数据不要存到token中，应该存一个能够唯一标识数据的id(可以是任意属性)
mongoose使用时并不需要自己启动自己电脑的数据库;

然后就是数据库文件的js
```js
const mongoose = require('mongoose');
const bcrypt = require('bcrypt')
mongoose.connect('mongodb://localhost:27017/express-auth', {
    useNewUrlParser: true
})

const User = mongoose.model('User', new mongoose.Schema({
    username: {type: String, unique: true},
    password:{type: String, set(val){
        return bcrypt.hashSync(val, 10)
    }}
}))

//User.db.dropCollection('users')
module.exports = { User}
```
mongoose我也是现学现用，数据库的查询语句他都已经封装好了，不用写复杂的查询sql语句

以上代码可见仓库：GitHub - zhoujingfighting/express-learning