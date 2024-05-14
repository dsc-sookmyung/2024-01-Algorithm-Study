import sys
input = sys.stdin.readline

N, K = map(int, input().split())
bags = [[0, 0]]
for _ in range(N):
    bags.append(list(map(int, input().split())))

DP = [[0] * (K+1) for _ in range(N+1)]
for i in range(1,N+1):
    w, v = bags[i]
    for j in range(1, K+1):
        if j >= w:
            DP[i][j] = max(DP[i-1][j], DP[i-1][j-w]+v)
        else:
            DP[i][j] = DP[i-1][j]

print(DP[N][K])