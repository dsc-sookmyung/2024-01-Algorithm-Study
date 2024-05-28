import sys
input = sys.stdin.readline

N = int(input())
childrens = [[0,0]] + [list(map(int, input().split())) for _ in range(N)]
K = int(input()) - 1

node = 1
while 1:
    if childrens[node][0] == -1 and childrens[node][1] == -1:
        print(node)
        break
    elif childrens[node][0] == -1:
        node = childrens[node][1]
    elif childrens[node][1] == -1:
        node = childrens[node][0]
    else:
        node = childrens[node][K%2]
        K = K//2