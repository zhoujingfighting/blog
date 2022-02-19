> 本笔记参考链接来源于 https://www.ruanyifeng.com/blog/2018/02/docker-tutorial.html， 感谢阮一峰老师

## 制作自己的 docker 容器

```js
$ git clone https://github.com/ruanyf/koa-demos.git
$ cd koa-demos
```

这个是阮一峰老师的仓库模板，跟着操作

### 编写 Dockerfile 文件

根目录下创建一个文本文件`.dockerignore`,写入以下内容(参考.gitignore)

```js
.git
node_modules
npm-debug.log
```

Dockerfile 内容如下

```js
FROM node:8.4
COPY . /app
WORKDIR /app
RUN npm install --registry=https://registry.npm.taobao.org
EXPOSE 3000
```

上面代码的含义

- FROM node:8.4：该 image 文件继承官方的 node image，冒号表示标签，这里标签是 8.4，即 8.4 版本的 node。
- COPY . /app：将当前目录下的所有文件（除了.dockerignore 排除的路径），都拷贝进入 image 文件的/app 目录。
- WORKDIR /app：指定接下来的工作路径为/app。
- RUN npm install：在/app 目录下，运行 npm install 命令安装依赖。注意，安装后所有的依赖，都将打包进入 image 文件。
- EXPOSE 3000：将容器 3000 端口暴露出来， 允许外部连接这个端口。

### 创建 image 文件

有了 Dockerfile 文件以后，就可以使用`docker image build`命令创建 image 文件了。

```js
$ docker image build -t koa-demo .
# 或者
$ docker image build -t koa-demo:0.0.1
```

上面代码中，`-t`参数用来指定 `image` 文件的名字，后面还可以用冒号指定标签。如果不指定，默认的标签就是 latest。最后的那个点表示 `Dockerfile` 文件所在的路径，上例是当前路径，所以是一个点。

如果运行成功，就可以看到新生成的 image 文件 koa-demo 了。

```js
docker image ls
```

### 生成容器

`docker container run`命令会从 image 文件生成容器。

```js
$ docker container run -p 8000:3000 -it koa-demo /bin/bash
```
- -p 参数：容器的 3000 端口映射到本机的 8000 端口
- -it 参数：容器的 Shell 映射到当前的 Shell，然后你在本机窗口输入的命令，就会传入容器
- koa-demo:0.0.1：image 文件的名字（如果有标签，还需要提供标签，默认是 latest 标签
- /bin/bash：容器启动以后，内部第一个执行的命令。这里是启动 Bash，保证用户可以使用 Shell
