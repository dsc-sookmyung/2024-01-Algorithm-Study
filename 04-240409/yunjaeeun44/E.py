import sys
input = sys.stdin.readline

N = int(input())
scores = list(map(int, input().split()))
Q = int(input())

answer = [0] * N
for i in range(1, N):
    if scores[i-1] > scores[i]:
        answer[i] = answer[i-1] + 1
    else:
        answer[i] = answer[i-1]

for _ in range(Q):
    x, y = map(int, input().split())
    print(answer[y-1]-answer[x-1])