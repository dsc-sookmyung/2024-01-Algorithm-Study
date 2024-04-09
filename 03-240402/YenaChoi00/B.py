# BOJ 21278

import sys

n, m = map(int, sys.stdin.readline().split())  # 건물 n, 도로 m
INF = int(1e9)

graph = [[INF] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a][b] = 1
    graph[b][a] = 1

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0


for k in range(1, n + 1):
    for a in range(1, n + 1):   # 출발 노드
        for b in range(1, n + 1):   # 도착 노드
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

min_sum = INF
result = list()
for i in range(1, n):
    for j in range(2, n + 1):
        sum_ = 0
        for k in range(1, n + 1):
            sum_ += min(graph[k][i], graph[k][j]) * \
                2 
        if sum_ < min_sum:
            min_sum = sum_
            result = [i, j, sum_]

print(*result)
