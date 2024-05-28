N, X = map(int, input().split())
visits = list(map(int, input().split())) + [0]
answer, num = 0, 0

tmp = sum(visits[0:X])
for i in range(N-X+1):
    if answer < tmp:
        answer = tmp
        num = 1
    elif answer == tmp:
        num += 1
    
    tmp -= visits[i]
    tmp += visits[i+X]

if answer == 0:
    print("SAD")
else:
    print(answer)
    print(num)
