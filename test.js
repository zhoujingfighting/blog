/**
 * Promise/A plus : https://promisesaplus.com/#requirements
 */
const PENDING = 'Pending';
const FULFILLED = 'Fulfilled';
const REJECTED = 'Rejected';
function PromiseZhou(resolver) {
    //resolver一定得是方程
    if (typeof resolver !== 'function') {
        throw new TypeError('Promise resolver ' + resolver + ' is not a function');
    }
    //这里参考Promise的规范
    if (!this instanceof PromiseZhou) {
        return new PromiseZhou(resolver);
    }
    let self = this;
    /**
     * 发布订阅模式 : 详情得参考nodejs的事件模块 : http://nodejs.cn/api/events.html
     */
    self.resolveCallbacks = [];//存放成功回调函数集合
    self.rejectCallbacks = [];//存放失败时的回调函数集合
    self.status = PENDING;//存放promise状态，三种。PENDING, FULFILLED, REJECTED 
    self.data = null//初始化resolved数据
    self.reason = null//初始化reject数据
    function resolve(value) {
        setTimeout(function () {
            /**
             * settimeout 产生闭包
             */
            if (self.status !== PENDING) {
                return
            }
            self.status = FULFILLED;//改变promise状态
            self.data = value;//存放待处理的数据
            for (let i = 0; i < self.resolveCallbacks.length; i++) {
                self.resolveCallbacks[i](value)
            }
        })
    }

    function reject(reason) {
        setTimeout(function () {
            if (self.status !== PENDING) {
                return
            }
            self.status = REJECTED;//同上，改变promise状态
            self.reason = reason;//保存错误信息
            for (let i = 0; i < self.rejectCallbacks.length; i++) {
                self.rejectCallbacks[i](reason)
            }
        })
    }
    /**
     * resolver调用resolve 和 reject参数
     */
    try {
        resolver(resolve, reject);
    } catch (error) {
        reject(error)
    }
}

function resolvePromise(promise, x, resolve, reject) {
    var then
    var thenCalledOrThrow = false

    if (promise === x) {
        return reject(new TypeError('Chaining cycle detected for promise!'))
    }

    if ((x !== null) && ((typeof x === 'object') || (typeof x === 'function'))) {
        try {
            then = x.then
            if (typeof then === 'function') {
                then.call(x, function rs(y) {
                    if (thenCalledOrThrow) return
                    thenCalledOrThrow = true
                    /**
                     * 得继续解析，解析一次，thenCalledOrThrow为 flag，利用了闭包
                     */
                    return resolvePromise(promise, y, resolve, reject)
                }, function rj(r) {
                    if (thenCalledOrThrow) return
                    thenCalledOrThrow = true
                    return reject(r)
                })
            } else {
                return resolve(x)
            }
        } catch (e) {
            if (thenCalledOrThrow) return
            thenCalledOrThrow = true
            return reject(e)
        }
    } else {
        return resolve(x)
    }
}
PromiseZhou.prototype.then = function then(OnResolved, OnRejected) {
    //检查参数的正确性
    OnResolved = (typeof OnResolved === 'function') ? OnResolved : function rs(tobeResolved) { return tobeResolved };
    OnRejected = (typeof OnRejected === 'function') ? OnRejected : function rj(tobeRejected) { throw tobeRejected };
    let self = this;
    let promiseZhou;
    if (self.status === FULFILLED) {
        return promiseZhou = new PromiseZhou(function (resolve, reject) {
            setTimeout(function () {
                try {
                    let resolvedData = OnResolved(self.data);
                    resolvePromise(promiseZhou, resolvedData, resolve, reject)
                } catch (error) {
                    return reject(error)
                }
            }, 0)
        })
    }
    if (self.status === REJECTED) {
        return promiseZhou = new PromiseZhou(function (resolve, reject) {
            setTimeout(function () {
                try {
                    let rejectData = onRejected(self.reason);
                    resolvePromise(promiseZhou, rejectData, resolve, reject)
                } catch (error) {
                    return reject(error)
                }
            })
        })
    }

    if (self.status === PENDING) {
        /**
         * function name need to be paid attention
         */
        return promiseZhou = new PromiseZhou(function (resolve, reject) {
            self.resolveCallbacks.push(function(value) {
                try {
                    let resolvedValue = OnResolved(value);
                    resolvePromise(promiseZhou, resolvedValue, resolve, reject)
                } catch (error) {
                    return reject(error)
                }
            })
            self.rejectCallbacks.push(function(reason) {
                try {
                    let rejectedValue = OnRejected(reason);
                    resolvePromise(promiseZhou, rejectedValue, resolve, reject)
                } catch (error) {
                    return reject(error)
                }
            })
        })
    }
}

PromiseZhou.prototype.catch = function (Onrejected) {
    return this.then(null, Onrejected)
}

PromiseZhou.resolve = function (value) {
    var promise = new PromiseZhou(function (resolve, reject) {
        resolvePromise(promise, value, resolve, reject)
    })
    return promise
}
PromiseZhou.reject = function (reason) {
    return new PromiseZhou(function (resolve, reject) {
        reject(reason)
    })
}
PromiseZhou.deferred = function () {
    var result = {};
    result.promise = new PromiseZhou(function (resolve, reject) {
        result.resolve = resolve;
        result.reject = reject;
    });

    return result;
}
const pp = PromiseZhou.resolve('123213');
const pp1 = pp.then(function (res) {
    console.log(res)
})
module.exports = PromiseZhou;