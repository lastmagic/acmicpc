var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

rl.on('line', function(line){
  const parsedLine = line.split(' ');
  const n1 = parsedLine[0];
  const n2 = parsedLine[1];

  console.log(n1 / n2);
})