# 점프 점프 (BOJ 14248)
n = int(input())
stone = [0] + list(map(int, input().split()))
s = int(input())
visited = [False] * (n+1)
cnt = 1


def dfs(x):
    global cnt

    for i in range(2):
        Ai = stone[x]

        if i == 0:
            move = x + Ai
        else:
            move = x - Ai

        if move < 1 or move > n:
            continue

        if not visited[move]:
            visited[move] = True
            cnt += 1
            dfs(move)


dfs(s)
print(cnt)
