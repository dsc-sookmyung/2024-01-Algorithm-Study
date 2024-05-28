function solution(l, r) {
  const answer = [];
  for (let i = l; i <= r; i++) {
    if (/^[05]+$/.test(String(i))) {
      answer.push(i);
    }
  }

  return answer.length === 0 ? [-1] : answer;
}
