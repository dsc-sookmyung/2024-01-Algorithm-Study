function solution(num_list) {
  let i = num_list.length - 1;
  let add =
    num_list[i] > num_list[i - 1]
      ? num_list[i] - num_list[i - 1]
      : num_list[i] * 2;
  return [...num_list, add];
}
