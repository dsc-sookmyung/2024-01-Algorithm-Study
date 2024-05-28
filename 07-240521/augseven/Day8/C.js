function solution(my_string, index_list) {
  var answer = [];
  for (var i = 0; i < index_list.length; i++) {
    answer.push(my_string.charAt(index_list[i]));
  }
  return answer.join("");
}
