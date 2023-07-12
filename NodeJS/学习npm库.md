## [issorted](https://github.com/dcousens/is-sorted)


入口文件：`index.js`,[参考](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array/sort)

```js

// 这里定义排序规则, 默认为升序
function defaultComparator (a, b) {
  return a - b
}

module.exports = function checksort (array, comparator) {
    // 排除是不是数组
    if (!Array.isArray(array)) throw new TypeError('Expected Array, got ' + (typeof array))

    // 定义排序规则，没有定义就是默认规则
    comparator = comparator || defaultComparator

    // 升序降序这里的处理都是一致的，🐱
    for (var i = 1, length = array.length; i < length; ++i) {
        if (comparator(array[i - 1], array[i]) > 0) return false
    }

    return true
}
```

## [decamelize](https://github.com/sindresorhus/decamelize)

感觉有点复杂，字符串的操作都有点麻烦：
需要debug一下！！