## Vue3起步尝试

* 初始化一个`VUE`项目

```js
npm update vur@latest
//这个是更新最新的vuecli

//1:初始化一个项目
vue create vue3-learning

//记住选择vue3模板
// 国内网速有点慢

--registry=https://registry.npmmirror.com
```

**vue-cli-serve**

这个命令在`@vue/cli-service`这里
这个就是一个脚手架,后面有需要可以再看源码

## Vue3带来的变化

* 使用proxy进行数据劫持




## methods里面为啥不能使用箭头函数

* 我们在methods要使用data返回对象的数据
  * 那么这个<font color=red>this是必须有值得</font>, 并且应该可以通过this获取到data返回对象中得数据;
* 那么我们这个this能不能是 <font color=red>windows</font>呢
  * 不可以是window,因为window中我们无法获取到data返回对象的数据
  * 但是如果我们是用箭头函数.那么this就会是`window`