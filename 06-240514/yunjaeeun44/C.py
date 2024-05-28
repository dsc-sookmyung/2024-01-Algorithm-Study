import sys
input = sys.stdin.readline

N, K = map(int, input().split())
stones = list(map(int, input().split()))

dp = [0] * N
dp[0] = 1
for start in range(0, N):
    for end in range(start+1, N):
        k = (end-start)*(1+abs(stones[start]-stones[end]))
        if k <= K and dp[start]:
            dp[end] = 1
            
if dp[N-1]:
    print("YES")
else:
    print("NO")