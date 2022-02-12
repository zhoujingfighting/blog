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

> 需要一个linux 虚拟机!!
> https://www.jenkins.io/doc/book/installing/linux/