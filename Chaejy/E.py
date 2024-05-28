n = int(input())

students = list(map(int,input().split()))
g = [0 for _ in range(1+n)]

for i in range(n+1):
    a = 0
    b = 10001
    for j in range(i,0,-1):
        a = max(a,students[j-1])
        b = min(b,students[j-1])
        g[i] = max(g[i], a - b + g[j - 1])
print(g[n])