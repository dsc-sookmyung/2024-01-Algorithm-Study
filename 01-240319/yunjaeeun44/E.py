def solution(n, tops):
    MOD = 10007
    a = [0] * (n + 1) #오른쪽에 위치한 위 방향 삼각형 포함
    b = [0] * (n + 1) #오른쪽에 위치한 위 방향 삼각형 미포함
    a[0] = 0 #위 방향 삼각형 하나만 있을 때
    b[0] = 1
    for k in range(1, n + 1): #아래 방향 삼각형 하나씩 덮기
        if tops[k - 1]:
            a[k] = (a[k - 1] + b[k - 1]) % MOD
            b[k] = (2 * a[k - 1] + 3 * b[k - 1]) % MOD
        else:
            a[k] = (a[k - 1] + b[k - 1]) % MOD
            b[k] = (a[k - 1] + 2 * b[k - 1]) % MOD
    return (a[n] + b[n]) % MOD