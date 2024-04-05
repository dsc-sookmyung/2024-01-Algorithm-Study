function solution(a, b) {
  var answer = 0;
  let first = String(a) + String(b);
  let second = String(b) + String(a);
  return parseInt(first > second ? first : second);
}
