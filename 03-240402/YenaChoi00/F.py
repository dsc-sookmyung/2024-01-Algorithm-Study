# BOJ 2230

import sys

n, m = map(int, sys.stdin.readline().split())

arr = []
for _ in range(n):
    arr.append(int(sys.stdin.readline()))
arr.sort()

left, right = 0, 0

result = int(2e9)

while left <= right and right < n:

    if arr[right]-arr[left] < m:
        right += 1

    else:
        result = min(result, arr[right]-arr[left])
        left += 1

print(result)
