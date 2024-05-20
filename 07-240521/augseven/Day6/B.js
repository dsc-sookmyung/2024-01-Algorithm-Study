function solution(n, control) {
  var answer = n;
  control = control.split("");
  for (let i = 0; i < control.length; i++) {
    answer =
      control[i] == "w"
        ? (answer += 1)
        : control[i] == "s"
        ? (answer -= 1)
        : control[i] == "d"
        ? (answer += 10)
        : (answer -= 10);
  }
  return answer;
}
