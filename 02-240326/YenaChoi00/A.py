n, m = map(int, input().split())


def factorial(n):
    if n > 1:
        return n * factorial(n-1)
    else:
        return 1


print(factorial(n) // (factorial(n-m) * factorial(m)))
