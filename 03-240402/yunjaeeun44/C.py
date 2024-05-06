N = int(input())
paper = list()
minus, zero, plus = 0, 0, 0
for _ in range(N):
    paper.append(list(map(int, input().split())))

def check(row, col, n):
    global minus, zero, plus
    curr = paper[row][col]
    
    for i in range(row, row+n):
        for j in range(col, col+n):
            if paper[i][j] != curr:
                next_n = n //3
                check(row, col, next_n)  # 1
                check(row, col + next_n, next_n)  # 2
                check(row, col + (2 * next_n), next_n)  # 3
                check(row + next_n, col, next_n)  # 4
                check(row + next_n, col + next_n, next_n)  # 5
                check(row + next_n, col + (2 * next_n), next_n)  # 6
                check(row + (2 * next_n), col, next_n)  # 7
                check(row + (2 * next_n), col + next_n, next_n)  # 8
                check(row + (2 * next_n), col + (2 * next_n), next_n)  # 9
                return
    
    #종이 안의 값이 모두 동일할 때
    if curr == -1:
        minus += 1
    elif curr == 0:
        zero += 1
    elif curr == 1:
        plus += 1
            
check(0, 0, N)

print(minus)
print(zero)
print(plus)



    