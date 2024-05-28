function solution(a, b, c, d) {
  const dice = [a, b, c, d];
  dice.sort((x, y) => x - y);

  const count = {};
  for (let num of dice) {
    count[num] = (count[num] || 0) + 1;
  }

  const uniqueValues = Object.keys(count).map(Number);
  const frequencies = Object.values(count);

  if (uniqueValues.length === 1) {
    return 1111 * a;
  }

  if (uniqueValues.length === 2) {
    if (frequencies.includes(3)) {
      const p = uniqueValues[frequencies.indexOf(3)];
      const q = uniqueValues[frequencies.indexOf(1)];
      return Math.pow(10 * p + q, 2);
    } else {
      const p = uniqueValues[0];
      const q = uniqueValues[1];
      return (p + q) * Math.abs(p - q);
    }
  }

  if (uniqueValues.length === 3) {
    const p = uniqueValues[frequencies.indexOf(2)];
    const otherValues = uniqueValues.filter((value) => value !== p);
    const q = otherValues[0];
    const r = otherValues[1];
    return q * r;
  }

  if (uniqueValues.length === 4) {
    return Math.min(...dice);
  }

  return 0;
}
