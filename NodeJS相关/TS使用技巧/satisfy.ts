interface Image {
  size: number;
  width: number;
  length: number;
};

type IImage = string | Image;


interface IUser {
  name: string;
  sex: string;
  test: IImage;
}

// bad demo
// 下面这种写法IUser.test没有string类型的代码提示
// const demo: IUser = {
//   name: "zhoujing",
//   sex: "male",
//   test: "dddd"
// };


const demo = {
  name: "zhoujing",
  sex: "male",
  test: "dddd"
} satisfies IUser;

console.log(demo.test.length)