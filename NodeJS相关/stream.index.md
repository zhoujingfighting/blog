## 为什么需要使用流(stream)

```js
const fs = require('fs')
fs.readFile(file, function (err, body) {
  console.log(body)
  console.log(body.toString())
})
```

> PS: 以前遇到过这种例子,读取文件过大时会出现报错,`buffer.js 报错`:

可以改成流的方式读取文件内容:
```js
const fs = require('fs')
fs.createReadStream(file).pipe(process.stdout)
```

`fs.createReadStream`创建一个可读流，连接了源头（上游，文件）和消耗方（下游，标准输出）。

执行上面代码时，流会逐次调用fs.read，将文件中的内容分批取出传给下游。 在文件看来，它的内容被分块地连续取走了。 在下游看来，它收到的是一个先后到达的数据序列。 如果不需要一次操作全部内容，它可以处理完一个数据便丢掉。 在流看来，任一时刻它都只存储了文件中的一部分数据，只是内容在变化而已。

这种情况就像是用水管去取池子中的水。 每当用掉一点水，水管便会从池子中再取出一点。 无论水池有多大，都只存储了与水管容积等量的水。
