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
     * 发布订阅模式 : 详情得参考nodejs的事件模块
     */
    self.resolveCallbacks = [];//存放成功回调函数集合
    self.rejectCallbacks = [];//存放失败时的回调函数集合
    self.status = PENDING;//存放promise状态，三种。PENDING, FULFILLED, REJECTED 

    function resolve(value) {
        if (self.status !== PENDING) {
            return
        }
        self.status = FULFILLED;//改变promise状态
        self.data = value;//存放待处理的数据
        for (let i = 0; i < self.resolveCallbacks.length; i++) {
            self.resolveCallbacks[i](value)
        }
    }

    function reject(reason) {
        if (self.status !== PENDING) {
            return
        }
        self.status = REJECTED;//同上，改变promise状态
        self.data = reason;
        for (let i = 0; i < self.rejectCallbacks.length; i++) {
            self.rejectCallbacks[i](reason)
        }
    }
    try {
        resolver(resolve, reject);
    } catch (error) {
        reject(error)
    }
}

//解析promise，返回的是经过处理的promise
function resolvePromise(promise, handledPromise, resolve, reject) {
    let then;
    let thenCalledOrThrow = false;//判断是否继续后续promise操作
    if (promise === handledPromise) {
        return reject(new TypeError('Chaining cycle detected for promise'));
    }
    if (handledPromise !== null && (typeof handledPromise === 'object' || typeof handledPromise === 'function')) {
        try {
            then = handledPromise.then;
            if (typeof then === 'function') {
                then.call(handledPromise, function rs(tobeResolved) {
                    if (thenCalledOrThrow) return
                    thenCalledOrThrow = true
                    return resolvePromise(promise, tobeResolved, resolve, reject)
                }, function rj(tobeRejected) {
                    if (thenCalledOrThrow) return;
                    thenCalledOrThrow = true
                    return reject(tobeRejected);
                })
            } else {
                return resolve(handledPromise)
            }
        }
        catch (error) {
            if (thenCalledOrThrow) return
            thenCalledOrThrow = true
            //为什么需要返回值呢？？？？
            return reject(error);
        }
    } else {
        //同上，为什么需要返回值
        return resolve(handledPromise)
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
            try {
                let resolvedData = OnResolved(self.data);
                resolvePromise(promiseZhou, resolvedData, resolve, reject)
            } catch (error) {
                return reject(error)
            }
        })
    }

    if (self.status === REJECTED) {
        return promiseZhou = new PromiseZhou(function (resolve, reject) {
            try {
                let rejectData = onRejected(self.data);
                resolvePromise(promiseZhou, rejectData, resolve, reject)
            } catch (error) {
                return reject(error)
            }
        })
    }

    if (self.status === PENDING) {
        return promiseZhou = new PromiseZhou(function (resolve, reject) {
            self.resolveCallbacks.push(function OnResolved(value) {
                try {
                    let resolvedValue = OnResolved(value);
                    resolvePromise(promiseZhou, resolvedValue, resolve, reject)
                } catch (error) {
                    return reject(error)
                }
            })
            self.rejectCallbacks.push(function OnRejected(reason) {
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

PromiseZhou.prototype.valueOf = function () {
    return this.data
}
PromiseZhou.resolve = function (value) {
    const promise = new PromiseZhou(function (resolve, reject) {
        resolvePromise(promise, value, resolve, reject);
    })
    return promise
}