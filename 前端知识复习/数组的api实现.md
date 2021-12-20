```js
/**
 * 给定平滑等级
 */
Array.prototype._flat = function (num) {
    let that = this;
    if (num === 0) {
        return that
    }
    let result = []
    for (let i = 0; i < that.length; i++) {
        if (!(that[i] instanceof Array)) {
            result = result.concat(that[i])
        } else {
            result = result.concat(that[i]._flat(num - 1))
        }
    }
    return result
}
console.log([1, 2, 4, [1, 2, [1, [1]]]]._flat(1))
console.log([1, 2, 4, [1, 2, [1, [1]]]]._flat(2))
console.log([1, 2, 4, [1, 2, [1, [1]]]]._flat(3))
//无限平滑
Array.prototype.infinitFlat = function () {
    let that = this;
    let result = []
    for (let i = 0; i < that.length; i++) {
        if (!(that[i] instanceof Array)) {
            result = result.concat(that[i])
        } else {
            result = result.concat(that[i].infinitFlat())
        }
    }
    return result
}
console.log([1, 2, 4, [1, 2, [1, [1,[1,2,[2]]]]]].infinitFlat())
```