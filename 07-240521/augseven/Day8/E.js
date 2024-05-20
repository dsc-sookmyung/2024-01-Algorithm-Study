function solution(my_string, queries) {
  let strArray = my_string.split("");

  for (let query of queries) {
    let [start, end] = query;
    let subStr = strArray.slice(start, end + 1).reverse();
    for (let i = start; i <= end; i++) {
      strArray[i] = subStr[i - start];
    }
  }

  return strArray.join("");
}
