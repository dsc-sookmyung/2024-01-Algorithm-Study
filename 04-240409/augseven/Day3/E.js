function solution(a, b) {
  let num = Number(`${a}${b}`);
  let answer = num > 2 * a * b ? num : 2 * a * b;
  return answer;
}
