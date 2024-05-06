import sys
input = sys.stdin.readline

def check(t, k):
    if (t == 1):        #단절점
        if (len(tree[k]) < 2):
            return("no")
        else:
            return("yes")        
    if (t == 2):        #단절선
        return("yes")

N = int(input())
tree = [[] for _ in range(N+1)]
bridges = [0]
for _ in range(N-1): #간선의 정보
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

q = int(input())
for _ in range(q): #간선의 정보
    t, k = map(int, input().split())
    print(check(t, k))