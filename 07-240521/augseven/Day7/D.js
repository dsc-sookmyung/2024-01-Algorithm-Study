function solution(n) {
  var answer = [n];
  for (let i = 0; i <= 1000; i++) {
    if (n % 2 == 0) {
      n = n / 2;
      answer.push(n);
    } else if (n % 2 == 1 && n != 1) {
      n = 3 * n + 1;
      answer.push(n);
    } else if (n === 1) {
      break;
    }
  }
  return answer;
}
