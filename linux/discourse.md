## 搭建 discourse 论坛

- 一种是源码构建
- 一种是`docker`

> 推荐 docker 构建,不需要下载那么多 package

### docker 构建的步骤

需要下载`git`,`docker`

#### 正式步骤

- mkdir -p `/var/www/discourse`
  - 因为后面`docker`的位置就是位于这个文件夹
- 修改 app 的配置文件`containers/app.yml`
  - UNICORN_WORKERS: 8
  - DISCOURSE_HOSTNAME: 'forum.zhoujing.icu'
    > 这个是你自己的域名,也就是最后被人访问的域名
  - #DOCKER_USE_HOSTNAME: true
  - DISCOURSE_DEVELOPER_EMAILS: '254644528@qq.com'
    > 这个是开发者的邮箱
  - DISCOURSE_SMTP_ADDRESS: zhoujing@sandboxae1f08b498fc451883d7c537630c5d2e.mailgun.org
    > 这个是邮件服务器用来接发邮件
  - #DISCOURSE_SMTP_PORT: 587
  - DISCOURSE_SMTP_USER_NAME:\* zhoujing@sandboxae1f08b498fc451883d7c537630c5d2e.mailgun.org
    > 这个是邮件服务器的用户名
  - DISCOURSE_SMTP_PASSWORD:\* aba60e08f55d6183098f3db657bee58e-50f43e91-fc3f256e
    > 这个是邮件服务器的密码


