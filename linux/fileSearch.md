## find命令

语法 : find [搜索范围] [匹配条件]
```js
find /etc -name init
find /etc -name *init*

```
只有init文件才会被搜索
### find / -size +204800
在根目录下查找大100MB的文件
+n 大于 -n 小于 n等于
1数据块 512字节 0.5MB
放放光
### find / -user +204800

查找home目录下的hello.txt文件
```shell
find /home -name hello.txt
```

### locate
### which
* 可以查看指令存放在哪个目录下!

### grep指令与管道符号

管道符号: '|'
* 钱一个指令的处理结果传给后面的指令处理

应用实例
```shell
# 请在hello.txt文件中.查找yes所在行,并显示行号
cat /home/hello.txt | grep -n "yes"
grep -n "yes" /home/hello.txt
```