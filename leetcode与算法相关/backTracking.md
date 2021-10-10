leetcode 39 combination sum 难度: medium

[Loading...leetcode.com/problems/combination-sum/![img](https://pic1.zhimg.com/v2-0c435ab948b151fd834be55f80a09794_180x120.jpg)](https://link.zhihu.com/?target=https%3A//leetcode.com/problems/combination-sum/)

作为回溯算法的入门题目，还是挺好的

* 题目梗要

Given an array of**distinct**integers`candidates`and a target integer`target`, return*a list of all **unique combinations** of*`candidates`*where the chosen numbers sum to*`target`*.*You may return the combinations in **any order**.

* 例子

**Input:** candidates = [2,3,6,7], target = 7
**Output:** [[2,2,3],[7]]

总结来看就是一个一维数组，给出所有数组和等于**target**的情况

```js
function combinationSum(candidates: number[], target: number): number[][] {
    const result: number[][] = [];
    const temp: number[] = [];
    backTracking(0);
    return result;
    function backTracking(position: number): void{
        const sum = temp.reduce( (a,b) => a + b, 0);
        if( sum > target) {
            return ;
        }else if (sum === target){
            result.push( temp.slice(0) );
            return ;
        }
        for(let i = position; i < candidates.length ; i ++){
            temp.push(candidates[i]);
            backTracking(i);
            temp.pop();
        }
    }
};
```

![img](https://pic3.zhimg.com/80/v2-3ee542fdf00ebd77061d2b98708d0336_720w.jpg)

总的来说还是按照回溯算法的思路来，比较简单

### 变种题目 Comnination Sum 2

leetcode 40 ,题目难度 medium

[https://leetcode.com/problems/combination-sum-ii/leetcode.com/problems/combination-sum-ii/![img](https://pic1.zhimg.com/v2-0c435ab948b151fd834be55f80a09794_180x120.jpg)](https://link.zhihu.com/?target=https%3A//leetcode.com/problems/combination-sum-ii/)

题目梗要大概一致，不同的是**数组中的每一个数字只能用一次**

**先贴写的超时代码**

```js
function combinationSum2(candidates: number[], target: number): number[][] {
    candidates.sort( (a,b) => a - b);
    const result: number[][] = [];
    const temp: number[] = [];
    backTracking(0);
    return Array.from(new Set(result.map( item => item.join(',') ))).map(item => item.split(',').map(index => Number(index)));
    function backTracking(position: number): void{
        /*应该有剪枝操作：how??*/
        const sum = temp.reduce( (a,b) => a + b, 0);
        if( sum > target) {
            return ;
        }else if (sum === target){
            result.push( temp.slice(0) );
            return ;
        }
        for(let i = position; i < candidates.length ; i ++){
            temp.push(candidates[i]);
            backTracking(i+1);
            temp.pop();
        }
    }
};
```

提交运行是显示超时了，超时案例是极限情况，还有一个方程比较影响这个速度

```js
Array.from(new Set(result.map( item => item.join(',') ))).map(item => item.split(',').map(index => Number(index)));
```

这一大串数组与字符串之间的转换，估计。。。。。哈哈哈哈哈。。。。！

接下来就是改进写法了，应该加入**剪枝操作**，因为数组中有可能有很多重复元素，所以得去重处理

> 剪枝操作我不熟悉，所以借鉴了很多网上资料，推荐下面这个

[代码随想录programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html#%E6%80%9D%E8%B7%AF![img](https://pic2.zhimg.com/v2-c42b9695f4d454fe80adeaf08fdcf9d9_180x120.jpg)](https://link.zhihu.com/?target=https%3A//programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html%23%E6%80%9D%E8%B7%AF)

后面就是学(chao)习(xi)写出TS版本的代码

```js
function combinationSum2(candidates: number[], target: number): number[][] {
    candidates.sort( (a,b) => a - b);
    const result: number[][] = [];
    const temp: number[] = [];
    backTracking(0);
    return result;
    function backTracking(position: number): void{
        const sum = temp.reduce( (a,b) => a + b, 0);
        if( sum > target) {
            return ;
        }else if (sum === target){
            result.push( temp.slice(0) );
            return ;
        }
        for(let i = position; i < candidates.length ; i ++){
            if (i > position && candidates[i] == candidates[i - 1]) {
                continue;
            }
            //以上这个判断就是剪枝操作
            temp.push(candidates[i]);
            backTracking(i+1);
            temp.pop();
        }
    }
};
```

![img](https://pic1.zhimg.com/80/v2-ec286a284f617a8bbd4d6ef0f340b560_720w.jpg)

就是这个回溯算法的流程图我不知道怎么表达出来。。。这个剪枝操作还是挺简短精悍的，牛逼！！