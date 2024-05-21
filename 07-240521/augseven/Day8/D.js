function solution(number) {
  var answer = 0;
  let total = number
    .split("")
    .map(Number)
    .forEach((e) => (answer += e));
  return answer % 9;
}
