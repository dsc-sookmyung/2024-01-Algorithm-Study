function solution(my_string, m, c) {
  var answer = [];
  let result = "";
  for (let i = 0; i < my_string.length; i += m) {
    answer.push(my_string.substring(i, i + m));
  }
  for (let j = 0; j < answer.length; j++) {
    result += answer[j][c - 1];
  }
  return result;
}
