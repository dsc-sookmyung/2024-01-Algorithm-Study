# 징검다리 건너기 BOJ 22869


n, k = map(int, input().split())

data = list(map(int, input().split()))

rock = [0]+data

dp = [-1]*(n+1)
dp[1] = 1

for i in range(1, n+1):
    if dp[i] == -1:
        continue
    for j in range(i+1, n+1):
        now = (j-i)*(1+abs(rock[i]-rock[j]))
        if now <= k:
            dp[j] = 1

    if dp[N] == 1:
        print("YES")
        exit()
