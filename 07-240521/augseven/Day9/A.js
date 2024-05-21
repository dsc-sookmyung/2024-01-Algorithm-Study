function solution(intStrs, k, s, l) {
  var answer = [];
  let result = 0;
  for (let i = 0; i < intStrs.length; i++) {
    result = intStrs[i].substr(s, l);
    if (+result > k) {
      answer.push(+result);
    }
  }
  return answer;
}
