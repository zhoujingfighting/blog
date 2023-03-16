const cp = require('child_process');
const n = cp.fork(`${__dirname}/child.js`);
// fork 只能启动nodejs的应用
n.on('message', (m) => {
    console.log('PARENT got message:', m);
    // n.disconnect();
});
n.send({ hello: 'my child' });