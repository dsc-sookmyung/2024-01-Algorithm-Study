import sys

n, k = map(int, input().split())
arr = [int(sys.stdin.readline()) for _ in range(n)]

start = 1
end = max(arr)

result = 0

while (start <= end):
    total = 0
    mid = (start + end) // 2

    for i in arr:
        if i >= mid:
            total += i // mid

    if total < k:
        end = mid - 1       # 새로운 값으로 다시 계산
    else:
        result = mid      # 가능한 값 저장
        start = mid + 1  # 더 큰 값으로도 가능한지 확인

print(result)
