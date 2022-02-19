> 用途： husky是一个npm包，安装后，可以很方便的在package.json配置git hook 脚本 。

比如，在 package.json 内配置如
```json
 "scripts": {
    "lint": "eslint src"
  },
  "husky": {
    "hooks": {
      "pre-commit": "npm run lint"
    }
  }
```
那么，在后续的每一次git commit 之前，都会执行一次对应的 hook 脚本npm run lint 。其他hook同理
