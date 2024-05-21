function solution(my_strings, parts) {
  var answer = "";
  for (let i = 0; i < parts.length; i++) {
    let [start, end] = parts[i];
    answer += my_strings[i].substring(start, end + 1);
  }
  return answer;
}
