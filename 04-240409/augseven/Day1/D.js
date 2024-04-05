const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", function (line) {
  input = line.split("");
  answer = "";
}).on("close", function () {
  for (let i = 0; i < input.length; i++) {
    if (input[i] === input[i].toUpperCase()) {
      answer += input[i].toLowerCase();
    } else {
      answer += input[i].toUpperCase();
    }
  }
  console.log(answer);
});
