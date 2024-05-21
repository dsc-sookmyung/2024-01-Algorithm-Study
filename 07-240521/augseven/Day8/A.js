function solution(x1, x2, x3, x4) {
  var answer = true;
  let e1 = x1 == false && x2 == false ? false : true;
  let e2 = x3 == false && x4 == false ? false : true;
  answer = e1 == true && e2 == true ? true : false;
  return answer;
}
