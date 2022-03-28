# linux行为准则: 万物皆文件

## 查看自己linux系统的信息
```js
cat /etc/os-release 

NAME="Alibaba Cloud Linux"
VERSION="3 (Soaring Falcon)"
ID="alinux"
ID_LIKE="rhel fedora centos"
VERSION_ID="3"
PLATFORM_ID="platform:al8"
PRETTY_NAME="Alibaba Cloud Linux 3 (Soaring Falcon)"
ANSI_COLOR="0;31"
HOME_URL="https://www.aliyun.com/"
```

**命令行 << < > >>之间的关系**

* `>>`是表示在原`文件后面追加内容`
* `>`表示重新覆盖原内容
* `<`表示标准输入, `后面的文件内容作为前面命令的输入`
  * 比如: `cat < test.txt` 等价于 `cat test.txt`
* 

linux中的IO共有三种形式
* 0 : 标准输入, stdin
* 1 : 标准输出, stdout
* 2 : 标准错误输出 ??这里好像有点问题


标准输入输出的例子
```shell
node test.js > test.txt
node test.js < test.txt
```


**管道的用法**

很多生信命令行工具需要提供多个输入和输出参数，这用在管道命令里可能会导致非常低效的情形（管道只接受一个标准输入和输出）。幸好，我们可以使用命令管道来解决此类问题。

命名管道，也称为FIFO。它是一个特殊的排序文件，命名管道有点像文件，它可以永久保留在你的文件系统上（估计本质就是文件吧~）。

比如我想查看某个文件（test1）的前两行并进行排序，操作如下：

```shell
wsx@wsx-ubuntu:~/script_learn$ cat test1
#!/bin/bash
# This script displays the date and who's logged on
echo -n "The time and date are: " 
date
echo  "Let's see who's logged into the system: " 
who
wsx@wsx-ubuntu:~/script_learn$ cat test1 | head -2 | sort
#!/bin/bash
# This script displays the date and who's logged on
```
