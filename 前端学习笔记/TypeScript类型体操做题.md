## Medium 题目

### Tuple to Object

Give an array, transform into an object type and the key/value must in the given array.

For example

```ts
const tuple = ["tesla", "model 3", "model X", "model Y"] as const;

type result = TupleToObject<typeof tuple>; // expected { tesla: 'tesla', 'model 3': 'model 3', 'model X': 'model X', 'model Y': 'model Y'}
```

题目答案 ：

```ts
type TupleToObject<T extends readonly any[]> = { [P in T[number]]: P };
```

<font color='red'>个人需要学习的知识点</font> \
T[number]是个什么骚操作？？？

> When Flatten is given an array type, it uses an indexed access with number to fetch out string[]’s element type. Otherwise, it just returns the type it was given.

```ts
type Flatten<T> = T extends any[] ? T[number] : T;

// Extracts out the element type

type Str = Flatten<string[]>;

type Str = string;

// Leaves the type alone.
type Num = Flatten<number>;

type Num = number;
```

T[number] will return type of T array element \
数组里面的 type 不就是数组每个数据本身嘛！

### First of Array

Implement a generic `First<T>` that takes an Array `T` and returns it's first element's type.

For example

```ts
type arr1 = ["a", "b", "c"];
type arr2 = [3, 2, 1];

type head1 = First<arr1>; // expected to be 'a'
type head2 = First<arr2>; // expected to be 3
```

题目答案 ：

```ts
type First<T extends any[]> = T extends [] ? never : T[0];
```

### Tuple length

For given a tuple, you need create a generic `Length`, pick the length of the tuple

For example

```ts
type tesla = ["tesla", "model 3", "model X", "model Y"];
type spaceX = [
  "FALCON 9",
  "FALCON HEAVY",
  "DRAGON",
  "STARSHIP",
  "HUMAN SPACEFLIGHT"
];

type teslaLength = Length<tesla>; // expected 4
type spaceXLength = Length<spaceX>; // expected 5
```

题目答案 ：

```ts
type Length<T extends any> = T extends { length: number } ? T["length"] : never;
```

> <font color='red'>T 应该有一个 length 属性</font>
