import sys

n, k = map(int, input().split())
arr = list(map(int, sys.stdin.readline().split()))

start = 0
end = 0

count_arr = [0] * (max(arr)+1)
answer = 0

while end < n:
    # start = end = 0 에서 시작해서, 하나씩 센다.
    # end가 앞으로 가며 해당 원소의 카운팅이 증가하고
    if count_arr[arr[end]] < k:
        count_arr[arr[end]] += 1
        end += 1
    else:
        # start가 앞으로 갈 때 원소의 카운팅이 감소한다.
        count_arr[arr[start]] -= 1
        start += 1
    answer = max(answer, end - start)

print(answer)
