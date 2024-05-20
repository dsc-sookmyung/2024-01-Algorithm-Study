N = int(input())
totalNum = int(input())
votes = list(map(int, input().split()))
students = list()
count = list()

for vote in votes:
    if vote in students: #이미 존재
        for i in range(len(students)):
            if vote == students[i]:
                count[i] += 1
    else: #아직 없음
        if len(students) == N:
            for i in range(len(students)):
                if count[i] == min(count):
                    del students[i]
                    del count[i]
                    break
        students.append(vote)
        count.append(1)
    
students.sort()
print(*students)