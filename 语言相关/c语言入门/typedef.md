 **C 语言提供了typedef 关键字， 我们可以使用它来为类型去一个新的名字**

> 有点像TS的**interface**

举个例子 ： 我们先定义一个术语 `BYTE`, 下面相当于定义了一个`char`类型的type
```c
typedef char BYTE;
```

下面可以看下具体怎么在代码

```c
#include <stdio.h>
#include <string.h>
 
typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;
 
int main( )
{
   Book book;
 
   strcpy( book.title, "C 教程");
   strcpy( book.author, "Runoob"); 
   strcpy( book.subject, "编程语言");
   book.book_id = 12345;
 
   printf( "书标题 : %s\n", book.title);
   printf( "书作者 : %s\n", book.author);
   printf( "书类目 : %s\n", book.subject);
   printf( "书 ID : %d\n", book.book_id);
 
   return 0;
}
```
`strcpy`是`c`语言的标准函数

```c

// man sc
#include <string.h>

char *
strcpy(char * dst, const char * src);
```

**typedef vs #define**


**#define** 是C指令，用于为各种数据类型定义别名，与**typedef**类似，但是它们有以下几点不同:
* **typedef** 仅限于为<font color=red></font>类型定义符号名称，**#define**不仅可以为类型定义名称，也能为数值定义别名，比如你可以定义1为one.
> 这里类型意思相当于C语言的数据类型，int，double, char bool等类型
* **typedef** 是由编译器执行解释的，**#define**语句是由预编译器进行处理的



<br>
<br>

**什么是预编译**

参考解释:[C 预处理器](https://www.runoob.com/cprogramming/c-preprocessors.html)

C 预处理器不是编译器的组成部分，但是它是编译过程中一个单独的步骤。简言之，C 预处理器只不过是一个文本替换工具而已，它们会指示编译器在实际编译之前完成所需的预处理。我们将把 C 预处理器（C Preprocessor）简写为 CPP。

所有的预处理器命令都是以井号（#）开头。它必须是第一个非空字符，为了增强可读性，预处理器指令应从第一列开始。下面列出了所有重要的预处理器指令：

| 指令 | 描述 |
| :-- | :-- |
| #define | 定义宏 |
| #include | 包含一个头文件 |
| #undef | 取消已定义的宏 |
| #ifdef | 如果宏已经定义，则返回真 |
| #if | 如果给定条件为真，则编译下面代码 |
| #else | #if 的替代方案 |
| #elif | 	如果前面的 #if 给定条件不为真，当前条件为真，则编译下面代码 |
| #endif | 结束一个 #if……#else 条件编译块 |
| #error | 当遇到标准错误时，输出错误消息 |
| #pragma | 使用标准化方法，向编译器发布特殊的命令到编译器中|



