{
  interface IUser {
    name: string;
    sex: string;
  }

  interface IDemoUser {
    name: string;
  }

  function isUser(user: unknown): user is IUser { // guard
    if (user != null && typeof user === "object") {
      return "sex" in user;
    }

    return false;
  }

  const dd: IUser = {
    name: "zhoujing",
    sex: "male",
  };
  if(isUser(dd)) {
    // 能够进入这个代码逻辑的就表明是IUser
    console.log(dd.sex);
  }
}