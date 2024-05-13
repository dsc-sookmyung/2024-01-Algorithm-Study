N, M = map(int, input().split())
di = [-1, 0, -1]
dj = [0, -1, -1]
answer = [[0 for _ in range(M)] for _ in range(N)]
maze = list()
for _ in range(N):
    maze.append(list( map(int, input().split())))

for i in range(N):
    for j in range(M):
        for x in range(3):
            if 0<=i+di[x]<N and 0<=j+dj[x]<M:
                answer[i][j] = max(answer[i][j], answer[i+di[x]][j+dj[x]])
        answer[i][j] += maze[i][j]
print(answer[N-1][M-1])