N, M = map(int, input().split())
switches = list() #각 스위치가 켜는 램프
lamps = [0] * (M+1) #각 램프 클릭 최대 수

for i in range(N):
    tmp = list(map(int, input().split()))[1:]
    switches.append(tmp)
    for j in tmp:
        lamps[j] += 1

for i in switches:
    answer = 1   
    for j in i:
        if lamps[j] -1 == 0:
            answer = 0
            break
    if answer == 1:
        print(answer)
        exit()
print(answer)