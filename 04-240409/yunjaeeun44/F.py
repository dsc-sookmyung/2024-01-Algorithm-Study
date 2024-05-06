N, M = map(int, input().split())
L = [0] + list(int(input()) for _ in range(N))
dp = [[0] * (M + 1) for _ in range(N + 1)]

for i in range(1, N+1):
    dp[i][0] = dp[i - 1][0]
    for j in range(1, M+1):
        dp[i][j] = dp[i - 1][j - 1] + L[i]
        dp[i][0] = max(dp[i][0], dp[i - j][j])
print(dp[N][0])