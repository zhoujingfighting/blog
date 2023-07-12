/**
 * 1: 取数组的第一个元素
 */

type GetFirst<Arr extends unknown[]> = Arr extends [infer first, ...unknown[]] ? first : never;
type a = GetFirst<[1, 2, 3, 4]>; // a = 1

/**
 * 2: 字符串匹配
 */

type StartWithPrefix<Input extends string, Prefix extends string> =
    Input extends `${Prefix}${string}` ? true : false;

type a1 = StartWithPrefix<"zhoujing", "zhou">; // true
type a2 = StartWithPrefix<"zhoujing", "jing">; // false

/**
 * 3: 获取ref的类型
 */

type GetRefProps<Props> =
    'ref' extends keyof Props
    ? Props extends { ref?: infer Value | undefined }
    ? Value
    : never
    : never;
type a3 = GetRefProps<{ 'a': 1, 'b': "2", 'ref': '3' }> // '3'

/**
 * 4: GetFunctionParam
 */
type GetFuncParam<Func extends Function> =
    Func extends (...args: infer value) => any ? value : never;
type a4 = GetFuncParam<(a: string, b: number) => string>; // [a:string, b:number]

interface ATest {
    name: string;
    sex: string
}
type Test = keyof ATest;
const a: Test = 'name'; // legal
const b: Test = 'age'; // illegal

/**
 * 5: 往数组里面push/shift一个元素
 */
type ArrPush<Arr extends unknown[], Ele extends unknown> = [...Arr, Ele]

type ArrTest = ArrPush<[1, 2, 3], "f">; // [1,2,3,'f]

/**
 * 6: 合并两个数组
 */
type Tuple1 = ['1', '2']
type Tuple2 = ['zhou', 'jing']

type Zip<Tuple1 extends [unknown, unknown], Tuple2 extends [unknown, unknown]> =
    Tuple1 extends [infer Tuple11, infer Tuple12] ?
    Tuple2 extends [infer Tuple21, infer Tuple22] ?
    [[Tuple11, Tuple21], [Tuple12, Tuple22]]
    : never
    : never
type ZipTest = Zip<Tuple1, Tuple2>; // [["1", "zhou"], ["2", "jing"]]