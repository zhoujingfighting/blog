FROM node:18

WORKDIR /app/Nodejs

# 拷贝当前目录下的package.json
COPY package.json .

COPY pnpm-* .

RUN npm config set registry https://registry.npmmirror.com/

RUN npm install -g pnpm

RUN pnpm install

EXPOSE 3000

COPY . .

CMD [ "npm ", "run test:rxjs:ajax" ]