const eventEmmiter = require('events');

const myEvent = new eventEmmiter();

myEvent.on('event1', () => {
    console.log('hhhhhh');
})

myEvent.emit('event1')
//console.log(Object.prototype.toString.call(global))
//工作目录

process.stdin.setEncoding('utf-8');
process.stdin.on('readable', (arg) => {
    let chunk = process.stdin.read()
    process.stdout.write(chunk)
})