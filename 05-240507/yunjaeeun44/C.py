N = int(input())
triangle = list()
answer = list()
for i in range(N):
    triangle.append(list(map(int, input().split())))
    answer.append([0]* (i+3))

answer[0][1] = triangle[0][0]
for i in range(1, N):
    for j in range(1, i+2):
        answer[i][j]= max(answer[i-1][j], answer[i-1][j-1])
        answer[i][j] += triangle[i][j-1]
print(max(answer[N-1]))
