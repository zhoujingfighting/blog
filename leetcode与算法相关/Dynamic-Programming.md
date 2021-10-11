动态规划入门题目当然是*斐波那契数列*

DP所有的题目思路分为三步(沃兹基硕德)

- 找出状态转移方程
- 确定初始值
- 循环

leetCode 509 Fibonacci Number , 难度 easy

[Loading...leetcode.com/problems/fibonacci-number/](https://link.zhihu.com/?target=https%3A//leetcode.com/problems/fibonacci-number/)

### 第一种解法:递归解法

```js
function fib(n: number): number {
    if( n === 0){
        return 0;
    }
    if( n === 1 || n === 2){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
};
```

![img](https://pic4.zhimg.com/80/v2-10953a4a18c49d86a5fedc7dc4623bf3_720w.jpg)

### 第二种解法: 动态规划

```js
function fib(n: number): number {
    if( n === 0){
        return 0;
    }
    if( n === 1 || n === 2){
        return 1;
    }
    //以上就是确定初始值
    let a: number = 1;
    let b: number = 1;
    let c: number = 2;
    for(let i = 3 ; i <= n ; i++){
        c = a + b;
        a = b;
        b = c 
    }
    //这个循环结构就是状态转移方程
    return c;
};
```

![img](https://pic1.zhimg.com/80/v2-90c54a26d0d274314d4996eb0835df3c_720w.jpg)

接下来好好讨论一下,这两种方法的不同点

- 方法一用的是简单粗暴的递归解法, 有一个非常致命的点是, n到后面越来越大时, 需要重复计算的fib(n)越来越多,可以列个二叉树类似的结构看一下,**重复计算**非常多!

- - 这里画个图就非常好理解

![img](https://pic4.zhimg.com/80/v2-13836727d3c9b149da1842146d8a3cef_720w.jpg)

- 方法二就是比较简单的动规写法了,确定初始值之后,然后列出状态转移方程

- - 状态转移方程按照我的理解就是由小及大,由已知的数据推出某种规律

可以看出运行效率提升了不止一点半点,这个题目算是动态规划的入门题目了,非常经典,和leetCode第一题 two sum一样,都是经典的不能再经典的题目了!

### 变种题目

1137.N-th Tribonacci Number 难度: easy

[Loading...leetcode.com/problems/n-th-tribonacci-number/](https://link.zhihu.com/?target=https%3A//leetcode.com/problems/n-th-tribonacci-number/)



```js
function tribonacci(n: number): number {
    if( n === 0){
        return 0;
    }
    if( n === 1 || n ===2 ){
        return 1;
    }
    let a: number = 0;
    let b: number = 1;
    let c: number = 1;
    let d: number = 2;
    for(let i = 3; i <= n ; i ++){
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return d;
};
```

思路基本一样,就是状态转移方程有点区别

### 爬楼梯

leetCode 70 Climbing stairs 难度: easy,思路同上

[Loading...leetcode.com/problems/climbing-stairs](https://link.zhihu.com/?target=https%3A//leetcode.com/problems/climbing-stairs/)

主要思路

- 爬到第n层楼梯,要么是第n-1层跳一下,要么是第n-2层跳两下,两者相加就是跳上第n层的方法

```js
function climbStairs(n: number): number {
    if( n === 1 ){
        return 1;
    }
    if( n === 2 ){
        return 2;
    }
    let a: number = 1;
    let b: number = 2;
    let c: number = 2;
    for(let i = 3; i<= n ; i++ ){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
};
```

### 爬楼梯的最小代价

leetCode 746 Min Cost Climbing Stairs 难度: easy

[Loading...leetcode.com/problems/min-cost-climbing-stairs](https://link.zhihu.com/?target=https%3A//leetcode.com/problems/min-cost-climbing-stairs/)

主要思路

- 这个是爬楼梯的变种题目,思路需要变化一下,DP三步还是那三步
- 首先是要求到达顶部的最小代价,这个就是问题的突破口,和爬楼梯一样,不同的是这次不是求跳的方法,而是求**跳的代价**,爬到第n层楼梯,要么是第n-1层跳一下,要么是第n-2层跳两下,那么调到第n层的最小代价就是Math.min(第n-1层的最小代价加上跳n-1层的花费, 第n-2层的最小代价加上跳n-2层的花费)

```js
dp[i] = Math.min( dp[i-2] + cost[i-2], dp[i-1] + cost[i-1] )
```

- 还有一个注意的点是,设置**DP数组的长度大小问题**,因为是要跳到楼顶,这个数组的长度是比cost数组长一个单位的,画个图就比较好理解

![img](https://pic2.zhimg.com/80/v2-e84de00abc8d5d9a7dcd3090bbf91339_720w.jpg)

```js
function minCostClimbingStairs(cost: number[]): number {
    let dp: number[] = new Array<number>(cost.length + 1);
    dp[0] = 0;
    dp[1] = 0;
    //初始跳是不需要代价的
    for(let i = 2; i < dp.length ; i ++){
        dp[i] = Math.min( dp[i-2] + cost[i-2], dp[i-1] + cost[i-1] )
    }
    return dp[dp.length -1];
};
```