def check(A, B, C, N):
    for a in range(N):
        for b in range(N):
            for c in range(N):
                if (a*A)+(b*B)+(c*C) == N:
                    return 1
    return 0
    
A, B, C, N = map(int, input().split())
print(check(A, B, C, N))


        