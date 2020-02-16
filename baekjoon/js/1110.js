var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

rl.on('line', function(line){
  const origin = Number.parseInt(line);
  let cnt = 0;
  let curNum = origin;
  while(true) {
    curNum = calcNextNumber(curNum);
    cnt++;
    if (curNum === origin) break;
  }
  console.log(cnt);
});

function calcNextNumber(number) {
  const prevTen = Math.floor(number / 10);
  const prevOne = number % 10;
  const next = prevTen + prevOne;
  const nextOne = next % 10;

  return Number.parseInt(`${prevOne}${nextOne}`);
}