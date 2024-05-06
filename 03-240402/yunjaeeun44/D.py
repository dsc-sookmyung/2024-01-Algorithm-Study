T = int(input())
for _ in range(T):
    N = int(input())
    before = list(input())
    after = list(input())
    WtoB, BtoW = 0, 0
    for i in range(N):
        if before[i] == 'W' and after[i] == 'B':
            WtoB += 1
        elif before[i] == 'B' and after[i] == 'W':
            BtoW += 1
    print(max(WtoB, BtoW))
            