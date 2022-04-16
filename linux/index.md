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

## 服务器的一些配置

参考文章：https://www.ruanyifeng.com/blog/2014/03/server_setup.html

**ssh设置**

* 找到本机的ssh公钥
```shell
cat ~/.ssh/id_rsa.pub
```
* 将公钥添加到服务器配置文件中
```shell
echo [id_rsa.pub] >> ~/.ssh/authorized_keys
```
* 进入服务器，编辑SSH配置文件/etc/ssh/sshd_config。
```shell
sudo cp /etc/ssh/sshd_config ~
# 把配置文件拷贝到用户根目录
sudo nano /etc/ssh/sshd_config
```
在配置文件中，将SSH的默认端口22改掉，可以改成从1025到65536之间的任意一个整数（这里假定为25000)。
```
Port 8081
```
然后，检查几个设置是否设成下面这样，确保去除前面的#号。
```shell
Protocol 2

PermitRootLogin no
# 这里是需要允许root用户登录的
PermitEmptyPasswords no
PasswordAuthentication no

RSAAuthentication yes
PubkeyAuthentication yes
AuthorizedKeysFile .ssh/authorized_keys

UseDNS no
```

接着，改变authorized_keys文件的权限。
```shell
sudo chmod 600 ~/.ssh/authorized_keys && chmod 700 ~/.ssh/
```

重启sshd
> 这里是分不同的linux系统有不同的操作
```
systemctl restart sshd.service
```