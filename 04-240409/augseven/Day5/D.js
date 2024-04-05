function solution(num_list) {
  var a = 1,
    b = 0;
  for (var i of num_list) {
    a *= i;
    b += i;
  }
  var answer = a > b ** 2 ? 0 : 1;
  return answer;
}
