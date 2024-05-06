def BT(index, answer):
    if index == size:
        print(*answer)
        exit()
    
    num1 = int(x[index]) #한 자리 숫자
    if not visited[num1]:
        visited[num1] = True
        answer.append(num1)
        BT(index+1, answer)
        visited[num1] = False
        answer.pop()
    
    if index+1 < size:
        num2 = int(x[index : index+2])
        if num2 <= N and not visited[num2]:
            visited[num2] = True
            answer.append(num2)
            BT(index+2, answer)
            visited[num2] = False
            answer.pop()
        
x = input()

size = len(x)
if size <= 9:
    N = size #N이 한자리 숫자
else:
    N = 9+(size-9)//2 #N이 두자리 숫자(최대 50)

visited = [0] * (N+1)

BT(0, [])
