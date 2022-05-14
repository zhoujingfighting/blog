* 序列传参
  
序列类型(`list`, `tuple`, `str`)作为参数列表传递, 其要求是: 序列的元素个数必须与参数的个数相同.

```python
def myfunc(sa,s2,s3):
    print(sa)
    print(s2)
    print(s3)
s1=[1,2,3,4,5] # list
s2=[1,2,3,4,5] # tuple
s3=[1,2,3,4,5] # str
myfunc(*s1)
myfunc(*s2)
myfunc(*s3) #都是三个参数
```

* 非序列化参数

字典关键字传参 : 字典的值传递给`键`对应的形参

```python
d1 = {"c": 33, "d": 11, "e": 434};
myfunc(**d1) #告诉编译器传递的是字典
```

* 缺省参数
    * 缺省参数必须从左至右依次存在, 如果有一个参数有缺省值,则其右侧的所有参数都必须有缺省参数(缺省值)
    * 缺省值可以有0个或者多个,甚至全部是有缺省参数

```python
def fn(a, b=10, c): #这个是错的
def fn(a = 1, b, c = 3): #这个也是错的 
```

* 星号元组传参

```python
def myfunc(*args): #传的是元组
    #语句块

def myfunc(*args): 
    print("实参个数是", len(args)) # 拿到形参个数
    print(args) # 打印数组
    for x in args:
        print('参数是:', x)

myfunc((1,2,3,4))
```

* 关键字传参

```py
def myfunc(a,b,*, c): # c一定要显式赋值

```

* 双星字典传参

```py
def myfunc(**kwargs): # 参数当成字典来处理
```

* 可变类型
  * 列表list, 集合set, 字典dict
* 不可变类型
  * fronzenset, tuple, str, numbers 

> 元组赋值报错


