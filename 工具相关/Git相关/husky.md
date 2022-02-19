> 用途： husky是一个npm包，安装后，可以很方便的在package.json配置git hook 脚本 。

新版husky实践

1. 安装husky

```bash
npm install -D husky
```


2. 在packgae.json中添加prepare脚本
```json

{
  "scripts": {
    "prepare": "husky install"
  }
}
```
prepare脚本会在npm install（不带参数）之后自动执行。也就是说当我们执行npm install安装完项目依赖后会执行 husky install命令，该命令会创建.husky/目录并指定该目录为git hooks所在的目录。

3. 添加git hooks，运行一下命令创建git hooks
```bash
npx husky add .husky/pre-commit "npm run test"
```
运行完该命令后我们会看到.husky/目录下新增了一个名为pre-commit的shell脚本。也就是说在在执行git commit命令时会先执行pre-commit这个脚本。pre-commit脚本内容如下：
```bash
#!/bin/sh
. "$(dirname "$0")/_/husky.sh"
   
npm run  test
```
可以看到该脚本的功能就是执行npm run test这个命令

需要注意的点
在项目中我们会使用commit-msg这个git hook来校验我们commit时添加的备注信息是否符合规范。在以前的我们通常是这样配置：
```json
{
  "husky": {
    "hooks": {
      "commit-msg": "commitlint -e $HUSKY_GIT_PARAMS" // 校验commit时添加的备注信息是否符合我们要求的规范
    }
  }
}
```
在新版husky中$HUSKY_GIT_PARAMS这个变量不再使用了，取而代之的是$1。在新版husky中我们的commit-msg脚本内容如下：

```bash
#!/bin/sh
. "$(dirname "$0")/_/husky.sh"

#--no-install 参数表示强制npx使用项目中node_modules目录中的commitlint包
npx --no-install commitlint --edit $1
```

这个脚本应该也能使用类似于npx husk add .husky/commit-msg "npx --no-install commitlint --edit $1"这样的命令进行添加，但是由于本人对shell编程不熟，不知道如何将$1当成一个普通的字符串输出的文件中去，所以一直没有成功。希望有知道的大神能够告诉我一下。


npx husky add .husky/commit-msg 'npx --no-install commitlint --edit "$1"' 

