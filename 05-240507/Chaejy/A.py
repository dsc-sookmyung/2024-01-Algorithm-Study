import sys

input = sys.stdin.readline

n = int(input())

lst = [input() for _ in range(n)]

stack = []

for l in lst:
    if 'push' in l.split()[0]:
        stack.append(int(l.split()[1]))
    elif 'top' in l:
        print(stack[-1]) if stack else print(-1)
    elif 'size' in l:
        print(len(stack))
    elif 'empty' in l:
        print(0) if stack else print(1)
    elif 'pop' in l:
        print(stack.pop()) if stack else print(-1)