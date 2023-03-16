/**
 * 学习使用stream的API
 */

const { spawn } = require('child_process');

const child = spawn('ls', ["../"]);

// process.stdin.pipe(child.stdin)

/// 1: 事件监听
child.stdout.on('data', (data) => {
  console.log(`child stdout:\n${data}`);
});

/// 2: 使用stream流来pipe标准readable流
child.stdout.pipe(process.stdout)


const { spawn } = require('child_process');