# 스택 BOJ 10828

import sys

n = int(sys.stdin.readline())

stack = [0] * n
pos = 0

for i in range(n):
    command = sys.stdin.readline().split()
    func = command[0]

    if (func == "push"):
        stack[pos] = int(command[1])
        pos += 1

    elif (func == "pop"):
        if (pos != 0):
            print(stack[pos-1])
            pos -= 1
        else:
            print(-1)

    elif (func == "top"):
        if (pos != 0):
            print(stack[pos-1])
        else:
            print(-1)

    elif (func == "size"):
        print(pos)

    elif (func == "empty"):
        if (pos != 0):
            print(0)
        else:
            print(1)
