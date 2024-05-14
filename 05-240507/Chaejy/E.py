import sys
input = sys.stdin.readline

a,b = map(int,input().split())
arr = [False,False]+([True]*(int(b**0.5)-1))

for i in range(2, int(b**0.5)+1):
    if arr[i]:
        if i*i > int(b**0.5):
            break
        for j in range(2*i, int(b**0.5)+1, i):
            arr[j] = False
cnt = 0

for i in range(2, len(arr)):
    if arr[i]:
        x = i*i
        while True:
            if x < a:
                x *= i
                continue
            if x > b:
                break
            cnt += 1
            x *= i
print(cnt)