var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

rl.on('line', function(line){
  const parsedLine = line.split(' ');
  const n1 = Number.parseInt(parsedLine[0]);
  const n2 = Number.parseInt(parsedLine[1]);

  if (n1 === 0 && n2 === 0) {
    rl.close();
  }

  console.log(n1 + n2);
}).on('close', () => {
  process.exit();
})