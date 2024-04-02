N = int(input())

lst = list(map(int, input().split()))

op = list(map(int, input().split()))

max_value = -1e9
min_value = 1e9


def dfs(n, temp):
    global max_value, min_value

    # 종료 조건
    if n == N-1:
        max_value = max(temp, max_value)
        min_value = min(temp, min_value)
        return

    if op[0] != 0:  # 덧셈
        op[0] -= 1
        dfs(n+1, temp + lst[n+1])
        op[0] += 1

    if op[1] != 0:  # 뺄셈
        op[1] -= 1
        dfs(n+1, temp - lst[n+1])
        op[1] += 1

    if op[2] != 0:  # 곱셈
        op[2] -= 1
        dfs(n+1, temp * lst[n+1])
        op[2] += 1

    if op[3] != 0:  # 나눗셈
        op[3] -= 1
        dfs(n+1, int(temp/lst[n+1]))
        op[3] += 1


dfs(0, lst[0])
print(max_value)
print(min_value)
