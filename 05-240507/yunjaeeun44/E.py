from collections import deque

N = int(input())
stones = list(map(int, input().split()))
first = int(input()) - 1
bfs = deque([first])
answer = [0] * N
answer[first] = 1

while(bfs):
    now = bfs.popleft()
    if now + stones[now] < N:
        bfs.append(now + stones[now])
        answer[now + stones[now]] = 1
    if now - stones[now] >= 0:
         bfs.append(now - stones[now])
         answer[now - stones[now]] = 1
print(sum(answer))