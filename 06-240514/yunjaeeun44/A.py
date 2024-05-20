import sys
input = sys.stdin.readline

stack = []
N = int(input())
for _ in range(N):
    command = input()
    if command[:4] == 'push': #변수 처리
        stack.append(int(command.split()[1]))
    elif command[:3] == 'pop':
        if len(stack) != 0:
            num = stack.pop()
            print(num)
        else:
            print(-1)
    elif command[:4] == 'size':
        print(len(stack))
    elif command[:5] == 'empty':
        if len(stack) != 0:
            print(0)
        else:
            print(1)
    elif command[:3] =='top':
        if len(stack) != 0:
            print(stack[-1])
        else:
            print(-1)    