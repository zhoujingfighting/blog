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

### find / -user +204800
