## 所用例子
```c
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 100;
    cout << "a + b" << a + b << endl;
}
```
## 打印文件的最后5行

```sh
tail --lines=5 ./test.txt
```
## 输出7的倍数
```sh
for((i=0;i<=500;i+=7)) do
    echo $i
done
```
> 双括号代表以C语言解析

## 输出第5行内容
```bash
head -n 5 | tail -n 1
```
> 现取出前五行,再取最后一行

**echo命令**
* echo -n, 取消行末的换行符,使得下一个提示符紧跟在输出内容后面
* echo -e, 如果不使用-e参数, 即默认参数下,引号会让特殊字符变成普通字符

```shell
echo "hello\nworld";
# hello
# world
```

**分号**

分号`;`是命令的结束符,使得一行可以放置多个命令,上一个命令执行结束后,再执行第二个命令.
```shell
clear;ls;
```

> ATTENTION: 这个是前面的命令执行完之后就会执行这个命令,不管<font color=red>成功与否</font>

**命令组合符&&和||**\

```shell
command 1 && command 2
```
上面命令的意思是，如果Command1命令运行成功，则继续运行Command2命令。

> 只有command1执行成功才能执行command2

```shell
command1 || command2
```

上面命令的意思是，如果`Command1命令运行失败`，则继续运行Command2命令。

> 只有command1命令失败,则继续运command2命令

**type命令**
Bash 本身内置了很多命令，同时也可以执行外部程序。怎么知道一个命令是内置命令，还是外部程序呢？

type命令用来判断命令的来源。

```shell
type echo
# echo is a shell builtin
type ls
# ls is /bin/ls
```

* shell builtin 表示echo是内部命令
* /bin/ls是外部命令
  
><font color=red>外部命令怎么理解????</font>

其他常见参数

* type -t:可以返回一个命令的类型：别名（alias），关键词（keyword），函数（function），内置命令（builtin）和文件（file）。
* type -a: 如果要查看一个命令的所有定义(位置)，

**转义**
反斜杠除了用于转义，还可以表示一些不可打印的字符。

* \a：响铃
* \b：退格
* \n：换行
* \r：回车
* \t：制表符

如果想要在命令行使用这些不可打印的字符，可以把它们放在`引号`里面，然后使用echo命令的-e参数。
```shell
echo a\tb
# a\t\b, 这里由于没有引号,所以不会解释
echo "a\tb"
# a    b
```


**删除变量**

```shell
unset NAME
```

还有另外一种办法,直接将这个变量赋值成空字符串,`foo=''`. <br>
这两个命令获得的结果是一致的.


**输出变量,export命令**
用户创建的变量仅可用于当前 Shell，子 Shell 默认读取不到父 Shell 定义的变量。为了把变量传递给子 Shell，需要使用`export`命令。这样输出的变量，对于子 Shell 来说就是环境变量.


`export`命令用来向子Shell 输出变量

```shell
NAME=foo
export NAME
```



