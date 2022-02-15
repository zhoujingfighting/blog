## 什么是Jenkins Pipeline

### Jenkins Pipeline总体介绍

> 1.Pipeline 是Jenkins 2.X核心特性，帮助Jenkins实现从CI到CD与DevOps的转变 \
2.Pipeline 简而言之，就是一套运行于Jenkins上的工作流框架，将原本独立
运行于单个或者多个节点的任务连接起来，实现单个任务难以完成的复杂流
程编排与可视化

* Jenkins Pipeline是一组**插件**，让Jenkins可以实现持续交付管道的落地和实施。
* 持续交付管道(CD Pipeline)是将软件从版本控制阶段到交付给用户或客户的完
整过程的自动化表现。
* 持续交付管道(CD Pipeline)是将软件从版本控制阶段到交付给用户或客户的完
整过程的自动化表现。


### Why Pipeline?

本质上，Jenkins 是一个自动化引擎，它支持许多自动模式。 Pipeline向Jenkins中添加了一组强大的工具, 支持用例 简单的CI到全面的CD pipeline。通过对一系列的相关任务进行建模, 用户可以利用pipeline的很多特性:
* 代码：Pipeline以代码的形式实现，通常被检入源代码控制，使团队能够编辑，
审查和迭代其CD流程。
* 可持续性：Jenkins重启或者中断后都不会影响Pipeline Job。
* 停顿：Pipeline可以选择停止并等待人工输入或批准，然后再继续Pipeline运行。
* 多功能：Pipeline支持现实世界的复杂CD要求，包括fork/join子进程，循环和
并行执行工作的能力。
* 可扩展：Pipeline插件支持其DSL的自定义扩展以及与其他插件集成的多个选项。

### 参考的资料链接
* https://wiki.eryajf.net/pages/63.html#%E5%89%8D%E8%A8%80%E7%B5%AE%E5%8F%A8

## 在linux虚拟机上的实现

参考资料来自于 [jenkins官方文档](https://www.jenkins.io/doc/book/installing/linux/)

### Prerequisites
最低硬件要求
* 256 MB of RAM
* 1 GB of drive space (although 10 GB is a recommended minimum if running Jenkins as a Docker container)

推荐硬件配置
* 4 GB+ of RAM
* 50 GB+ of drive space

> 需要分清自己的linux系统版本！！

### 安装Java环境（我的linux虚拟机是centos版本）
```bash
yum update 
# 更新的package更新到源中的最新版
yum search openjdk
# 查看完之后选一个jdk8版本的java
yum install -y javaJdk@version
# -y 选项是可以回答所有安装过程的问题为yes,不用手动操作
java -version
```

### 安装Jenkins
```bash
sudo wget -O /etc/yum.repos.d/jenkins.repo \
    https://pkg.jenkins.io/redhat/jenkins.repo
sudo rpm --import https://pkg.jenkins.io/redhat/jenkins.io.key
sudo yum upgrade
sudo yum install chkconfig java-devel
sudo yum  install jenkins
# 如果是root用户则不用sudo
```

### 启动Jenkins 
```bash
systemctl daemon-reload
# https://unix.stackexchange.com/questions/364782/what-does-systemctl-daemon-reload-do
systemctl start jenkins
systemctl status jenkins
```


后面的按照官方教程一步步操作就好了
