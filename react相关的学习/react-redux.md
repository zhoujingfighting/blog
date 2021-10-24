## Redux的学习
### 森么是redux
- `Redux`是一个用于javaScript的状态容器, 提供可以预测化的状态管理
- `Redux`可以构建一致化应用,运行于不同的环境(客户端,服务器,原生应用), 并且易于测试
- Redux除了和`React`一起使用外,还支持其他`界面库`,而且它体积小而精焊(2kb)
### Redux设计初中
- 管理数据状态
- 状态不断变化的state非常麻烦,不同组件的相互影响非常麻烦
### Redux三大核心
- 单一数据源
- State是只读的
  - 改变state的唯一方法是触发`action`, action是一个用于描述已发生事件的普通对象
  - > store.dispath(action)
- 使用纯函数来执行修改
  - 为了描述action如何改变state tree, 你需要去编写reducers
### Redux的组成
#### State-状态
就是我们传递的数据,那么我们在用React开发项目时,大致可以把state分为三类
- DomainState: 可以理解为服务器端的数据, 比如: 获取用户的信息,商品的列表等等
- UI State: 决定当前UI决定展示的状态, 比如: 弹框的显示隐藏,受控组件等等
- App State: App级别的状态, 比如当前是否请求loading,当前路由信息可能被多个组件去使用到的状态等
#### Action-事件
actions是把数据从应用传到`store`的载体, 它是store数据的唯一来源, 一般来说,我们可以通过`store.dispatch(action)`将action传递给sore
- action本质就是一个`JavaScript`对象
- action对象内部必须有一个type属性来表示执行的动作
- 多数情况下.这个type会被定义为要执行的动作