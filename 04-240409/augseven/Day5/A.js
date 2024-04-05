function solution(code) {
  let answer = "";
  let mode = 0;
  for (let i = 0; i < code.length; i++) {
    if (code[i] === "1") {
      mode = mode === 0 ? 1 : 0;
    } else if (code[i] !== "1" && i % 2 === mode) {
      answer += code[i];
    }
  }
  if (answer === "") {
    return "EMPTY";
  } else {
    return answer;
  }
}
