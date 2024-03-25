T = int(input())
for _ in range(T):
    x1, y1, x2, y2 = map(int, input().split())
    answer = 0
    N = int(input())
    for i in range(N):
        cx, cy, r = map(int, input().split())
        distance1 = ((cx-x1)**2 + (cy-y1)**2)**(1/2) #출발점과 원 중심의 거리
        distance2 = ((cx-x2)**2 + (cy-y2)**2)**(1/2) #출발점과 원 중심의 거리
        if distance1 < r and distance2 < r: #출발점과 도착점이 모두 원 안에 존재
            continue
        elif distance1 > r and distance2 > r: #출발점과 도착점이 모두 원 밖에 존재
            continue
        else: #출발점과 도착점 중 하나가 원 안에 존재
            answer += 1
    print(answer)