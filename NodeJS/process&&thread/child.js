
process.send({ hello: 'my parent' });

process.on('message', (m) => {
  console.log('CHILD got message:', m);
  process.disconnect()
});