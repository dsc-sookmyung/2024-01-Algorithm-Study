T = int(input())
for i in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    distance = ((x1-x2)**2 + (y1-y2)**2)**(1/2)
    if distance==0 and r1==r2: #동일
        print(-1)
    elif abs(r1-r2)==distance or r1+r2==distance: #내접, 외접
        print(1)
    elif abs(r1-r2) < distance < (r1+r2) : #두 점에서 만날 때
        print(2)
    else:
        print(0)