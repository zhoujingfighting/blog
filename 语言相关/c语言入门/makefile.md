## makefile 的规则

**makefile 语法**
```shell
target ... : prerequisites ...
    command
    ...
    ...
```

**target**
可以是一个`object file`, 也可以是一个`可执行文件`,还可以是一个标签`(lable)`.
对于`标签`这种特性,<font color=red>在后续的`伪目标`章节中会有叙述</font>

**prequisites**
生成该target所依赖的文件和/或target

**command**
该target要执行的命令(任意的`shell`命令)

## Makefile里有什么

Makefile里主要包含了五个东西：`显式规则`、`隐晦规则`、`变量定义`、`文件指示`和`注释`。

* 显式规则。显式规则说明了如何生成一个或多个目标文件。这是由Makefile的书写者明显指出要生成的文件、文件的依赖文件和生成的命令。
* 隐晦规则。由于我们的make有自动推导的功能，所以隐晦的规则可以让我们比较简略地书写 Makefile，这是由make所支持的。
* 变量的定义。在Makefile中我们要定义一系列的变量，变量一般都是字符串，这个有点像你C语言中的宏，当Makefile被执行时，其中的变量都会被扩展到相应的引用位置上
* 文件指示。其包括了三个部分，一个是在一个Makefile中引用另一个Makefile，就像C语言中的include一样；另一个是指根据某些情况指定Makefile中的有效部分，就像C语言中的预编译#if一样；还有就是定义一个多行的命令。有关这一部分的内容，我会在后续的部分中讲述。
* 注释。Makefile中只有行注释，和UNIX的Shell脚本一样，其注释是用 # 字符，这个就像C/C++中的 // 一样。如果你要在你的Makefile中使用 # 字符，可以用反斜杠进行转义，如：`\#`.

> 最后还值得一提的是,在makefile中的命令,必须以`Tab`键开始.

## Makefile的文件名

默认的情况下，make命令会在当前目录下按顺序找寻文件名为“GNUmakefile”、“makefile”、“Makefile”的文件，找到了解释这个文件。在这三个文件名中，最好使用“Makefile”这个文件名，因为，这个文件名第一个字符为大写，这样有一种显目的感觉。最好不要用“GNUmakefile”，这个文件是GNU的make识别的。有另外一些make只对全小写的“makefile”文件名敏感，但是基本上来说，大多数的make都支持“makefile”和“Makefile”这两种默认文件名。

当然，你可以使用别的文件名来书写Makefile，比如：“Make.Linux”，“Make.Solaris”，“Make.AIX”等，如果要指定特定的Makefile，你可以使用make的 `-f` 和 `--file` 参数，如： `make -f Make.Linux` 或 `make --file Make.AIX`.

## 引用其它的Makefile

在Makefile使用`include`关键字可以把别的Makefile包含进来，这很像C语言的`#include`，被包含的文件会原模原样的放在当前文件的包含位置。`include`的语法是：
```shell
include <filename>
```

`filename`可以是当前操作系统Shell的文件模式（可以包含路径和通配符).
在`include`前面可以有一些空字符，但是绝不能是<font color=red>**Tab**</font>键开始。 include 和 <filename> 可以用一个或多个空格隔开。举个例子，你有这样几个Makefile： `a.mk` 、 `b.mk` 、 `c.mk` ，还有一个文件叫 `foo.make` ，以及一个变量 `$(bar)` ，其包含了 `e.mk` 和 `f.mk` ，那么，下面的语句：
```shell
include foo.make *.mk $(bar)
```
等价于:
```shell
include foo.make a.mk b.mk c.mk e.mk f.mk
```