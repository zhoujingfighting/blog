## nodejs的流的类型

Nodejs中有四种基本的流类型
* Writable: 可以写入数据的流(例如, fs.createWriteStream());
* Readble: 可以从中读取数据的流（例如，fs.createReadStream());
  
> fs只是其中的一个例子

* Duplex: Readable 和 Writable 的流（例如，`net.Socket`）。双向操作等
* Transform: 可以在写入和读取数据时修改或转换数据的 Duplex 流（例如，`zlib.createDeflate()`(TODO:这个是个啥))

此外，此模块还包括实用函数 `stream.pipeline()`、`stream.finished()`、`stream.Readable.from()` 和 `stream.addAbortSignal()`。

## 缓冲

`Writable` 和 `Readable` 流都将数据存储在 <font color=red>内部缓冲区中</font>。

可能缓冲的数据量取决于传给流的构造函数的 highWaterMark(TODO:这是个啥??) 选项。 对于普通的流，highWaterMark 选项指定字节的总数。 对于在对象模式下操作的流，highWaterMark 指定对象的总数。

当实现调用 `stream.push(chunk)` 时，数据缓存在 Readable 流中。 如果流的消费者没有调用 stream.read()，则数据会一直驻留在内部队列中，直到被消费。

一旦内部读取缓冲区的总大小达到 highWaterMark 指定的阈值，则流将暂时停止从底层资源读取数据，直到可以消费当前缓冲的数据（也就是，流将停止调用内部的用于填充读取缓冲区 readable._read() 方法）。

当重复调用 writable.write(chunk) 方法时，数据会缓存在 Writable 流中。 虽然内部的写入缓冲区的总大小低于 highWaterMark 设置的阈值，但对 writable.write() 的调用将返回 true。 一旦内部缓冲区的大小达到或超过 highWaterMark，则将返回 false。

stream API 的一个关键目标，尤其是 stream.pipe() 方法，是将数据缓冲限制在可接受的水平，以便不同速度的来源和目标不会压倒可用内存。

highWaterMark 选项是阈值，而不是限制：它规定了流在停止请求更多数据之前缓冲的数据量。 它通常不强制执行严格的内存限制。 特定的流实现可能会选择实施更严格的限制，但这样做是可选的。

由于 Duplex 和 Transform 流都是 Readable 和 Writable，因此每个流都维护两个独立的内部缓冲区，用于读取和写入，允许每一端独立操作，同时保持适当且高效的数据流。 例如，net.Socket 实例是 Duplex 流，其 Readable 端允许消费从套接字接收的数据，其 Writable 端允许将数据写入套接字。 因为数据可能以比接收数据更快或更慢的速度写入套接字，所以每一端都应该独立于另一端进行操作（和缓冲）。

内部缓冲的机制是内部的实现细节，可能随时更改。 但是，对于某些高级实现，可以使用 writable.writableBuffer 或 readable.readableBuffer 检索内部的缓冲区。 不鼓励使用这些未记录的属性。

## 流消费者的 API
几乎所有的Nodejs应用程序,无论多么简单,都以某种方式使用流;以下是在实现`HTTP`服务器的 Node.js 应用程序中使用流的示例

```js
const port = 8081
const http = require('http');
const server = http.createServer((req, res) => {
    // `req` 是 http.IncomingMessage，它是可读流。
    // `res` 是 http.ServerResponse，它是可写流。
    console.log(req.method);
    //这里有很多方法可以自行点击查看
})
server.listen(port, () => {
    console.log(`${port} is running`)
});

```
Writable 流（例如示例中的 res）暴露了用于将数据写入流的方法，例如 write() 和 end()。

> res.write和res.end是比较经典的方法

## pipe方法(管道)
这个就非常类似于linux的管道方法
```
readableSrc.pipe(writableDest)
```
导出可读流的输出--`源数据`,作为可写流的输入--`目标`.源数据必须是一个可读流,目标数据必须是一个可写流.
可以像linux中那样链式调用
```
readableSrc
  .pipe(transformStream1)
  .pipe(transformStream2)
  .pipe(finalWrtitableDest)

```
pipe 方法返回目标流，可以让我们做链式调用 pipe。对于流 a (readable), b and c (duplex), and d(writable), 我们可以:
```shell
a.pipe(b).pipe(c).pipe(d)
# Which is equivalent to:
a.pipe(b)
b.pipe(c)
c.pipe(d)
# Which, in Linux, is equivalent to:
$ a | b | c | d

```

pipe方法是消费流最简单的方法。通常建议使用`pipe`方法或者事件来消费流，但是不要混合使用它们。通常当你使用`pipe`方法时，不需要使用事件，但是如果你学要用更多自定义的方式使用流，那么就需要使用事件的方式。

## 可写流

可写流是数据写入目标的抽象。
`writable`流的示例包括:
* 客户端的HTTP请求
* 客户端的HTTP响应
* 文件系统写入流
* 压缩流
* 加密流
* TCP套接字
* 子进程标准输入
* process.stdout, process.stderr