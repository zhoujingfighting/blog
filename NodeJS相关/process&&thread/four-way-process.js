/**
 * 在nodejs中有四种方式创建进程
 * 1 : spawn
 * 2 : exec
 * 3 : execfile
 * 4 : fork
 */

const { spawn } = require('child_process');

const child = spawn('ls', ["../"]);
// 一般来说，spawn不会直接创建shell命令，但是可以使用下面命令可以达到与exec一样的效果
const child1 = spawn("ls ../ && echo $ZHOUJING", {
  stdio:"inherit",
  shell: true,
  env:{ZHOUJING:"niubi"},
  // cwd:"fefef"，这里就是执行这个shell脚本所在的directory目录
}) // child1是一个shell进程

child.stdout.pipe(process.stdout)
// child1.stdout.pipe(process.stdout)
