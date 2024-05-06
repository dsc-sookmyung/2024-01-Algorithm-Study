conputerNum = int(input())
N = int(input())
visited = [0] *(conputerNum+1)
graph = [[] for _ in range(conputerNum+1)]

for _ in range(N):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

tmp = [1]
visited[1] = 1
while tmp:
    now = tmp.pop()
    for i in graph[now]:
        if visited[i] == 0:
            tmp.append(i)
            visited[i] = 1
print(sum(visited)-1)
