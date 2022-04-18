### 针对文件比较常见的命令

```shell
ls -ld : -d选项是只列出当前文件夹信息
ls -i 查询任意文件的i节点信息
mkdir -p 递归创建不存在的目录 

rmdir XXX : 删除空目录

cp -r 表示复制目录
cp -p 保留文件属性

mv 剪切命令 文件或者文件夹
touch 创建新文件
* 不加路径会是在当前路径
* 加了路径就是绝对地址
创建带有空格的文件
touch "program files"  双引号引起来,但是不建议使用空格

cat 打开文件(内容过过多只显示的最后一页)
tac 倒着显示文件
more 分页显示文件内容
    - 空格和F是一页一页往后翻\
    - 回车是一行一行往后翻
    - 缺点是不能往回翻页

less 与more类似
    - pageup往回翻页

head 只显示文件前几行
- head -n 7 xxx

tail 只显示最后几行
- tail -n 3 xxx
- tail -f 动态监视文件变化
```

### 文件夹(文件)的链接
ln 硬链接

ln -s 软链接

```shell
ln -s [源文件] [目标文件] : 绝对路径
```

软连接相当于windows快捷方式
需要找到源文件,权限取决于源文件的权限
硬链接特性
    - cp -p + `同步更新`
    - 通过i节点时别
    - 不能跨分区
    - 不能针对目录使用

### find命令

语法 : find [搜索范围] [匹配条件]
```js
find /etc -name init
find /etc -name *init*

```
只有init文件才会被搜索

**find / -size +204800**

在根目录下查找大100MB的文件
+n 大于 -n 小于 n等于
1数据块 512字节 0.5MB
放放光

**find / -user +204800**

查找home目录下的hello.txt文件
```shell
find /home -name hello.txt
```
### which
可以查看指令存放在哪个目录下!
```shell
which node
which npm
```

### grep指令与管道符号

管道符号: '|'
前一个指令的处理结果传给后面的指令处理

应用实例
```shell
# 请在hello.txt文件中.查找yes所在行,并显示行号
cat /home/hello.txt | grep -n "yes"
grep -n "yes" /home/hello.txt
```







