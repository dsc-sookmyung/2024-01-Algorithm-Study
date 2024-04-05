function solution(n) {
  var answer = 0;
  let arr = [];
  if (n % 2 == 1) {
    arr = Array.from({ length: n + 1 }, (_, index) => index).filter(
      (e) => e % 2 === 1
    );
    answer = arr.reduce((a, b) => a + b);
  } else {
    arr = Array.from({ length: n + 1 }, (_, index) => index)
      .filter((e) => e % 2 === 0)
      .map((e) => e * e);
    answer = arr.reduce((a, b) => a + b);
  }
  return answer;
}
