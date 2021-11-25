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