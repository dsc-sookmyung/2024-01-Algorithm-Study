function solution(a, b, c) {
  var answer = 0;
  answer =
    a != b && b != c && a != c
      ? a + b + c
      : (a != b && b != c && a == c) ||
        (a != b && b == c && a != c) ||
        (a == b && b != c && a != c)
      ? (a + b + c) * (Math.pow(a, 2) + Math.pow(b, 2) + Math.pow(c, 2))
      : (a + b + c) *
        (Math.pow(a, 2) + Math.pow(b, 2) + Math.pow(c, 2)) *
        (Math.pow(a, 3) + Math.pow(b, 3) + Math.pow(c, 3));
  return answer;
}
