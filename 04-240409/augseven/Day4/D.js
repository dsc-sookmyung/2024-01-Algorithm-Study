function solution(ineq, eq, n, m) {
  let answer;
  let exp = ineq + eq;

  if (exp === ">=") {
    answer = n >= m;
  } else if (exp === "<=") {
    answer = n <= m;
  } else if (exp === ">!") {
    answer = n > m;
  } else {
    answer = n < m;
  }

  return answer == true ? 1 : 0;
}
