function solution(a, d, included) {
  let totalSum = 0;
  let currentTerm = a;
  for (let i = 0; i < included.length; i++) {
    if (included[i]) {
      totalSum += currentTerm;
    }
    currentTerm += d;
  }
  return totalSum;
}
