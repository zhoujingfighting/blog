
slidev官网：https://sli.dev/guide/why.html


为什么学这个呢，因为这个定西感觉还挺有趣的，顺便一起学了学`vercel`部署；

* 第一步根据官网操作来做，`npm init slidev@latest`初始化项目
* 下面会有一个`vercel.json`文件
* 下一步需要修改一些文件


vercel部署是可以托管第三方平台的，包括`GitHub`或者`第三方git平台`

```json
  "scripts": {
    "build": "slidev build -o ./public",// 修改脚本
    "dev": "slidev --open",
    "export": "slidev export", // 导出PDF
    "help": "slidev build --help"
  }
```

因为vercel部署需要public文件夹。所以修改了官方默认的`build`文件夹，改成`public`文件夹，
按照vercel操作就好，不过我们其实是需要自己的一个域名，在自己的`域名服务器`上解析一个域名