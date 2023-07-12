// 避免使用纯数字来作为enum
enum BadState {
  Inprogress,
  Success,
  Fail
}

BadState.Inprogress;// actually is 0
BadState.Success;// actually is 1
BadState.Fail;// actually is 2

const badCheckState = (state: BadState) => {
  // do something
}

badCheckState(100); // runtime error

// actually when we try to use this function, we want the argument
// to be in the range of BadState

type GoodState = "Inprogress" | "Success" | "Fail";

const goodStateCheck = (state: GoodState) => {
  // do something
}

// goodStateCheck(122); this will cause compiler error