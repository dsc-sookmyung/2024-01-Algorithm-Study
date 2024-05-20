function solution(my_string, s, e) {
  let rev = my_string
    .substring(s, e + 1)
    .split("")
    .reverse()
    .join("");
  let answer = my_string.substr(0, s) + rev + my_string.substr(e + 1);
  return answer;
}
