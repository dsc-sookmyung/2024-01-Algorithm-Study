import sys
from collections import deque

def fire_move():
    size = len(fires)
    while size:
        x, y = fires.popleft()
        for ddx, ddy in zip(dx, dy):
            nx = x + ddx
            ny = y + ddy
            if 0 <= nx < w and 0 <= ny < h and building[ny][nx] == '.':
                fires.append([nx, ny])
                building[ny][nx] = '*'
        size -= 1

def BFS():
    while sanggeuns:
        fire_move()
        size = len(sanggeuns)
        while size:
            x, y, sec = sanggeuns.popleft()
            for ddx, ddy in zip(dx, dy):
                nx = x + ddx
                ny = y + ddy
                if 0 <= nx < w and 0 <= ny < h:
                    if building[ny][nx] == '.' and visit[ny][nx]==0:
                        sanggeuns.append([nx, ny, sec+1])
                        visit[ny][nx] = 1
                else: 
                    return sec + 1
            size -= 1
    return 0
            


input = sys.stdin.readline

dx = [0,1,-1,0]
dy = [1,0,0,-1]

building = [] #불 실시간 반영
fires = deque(list()) #다음에 번질 불의 위치들을 담는 큐
sanggeuns = deque(list()) #[상근이의 위치, 탈출한 시간]을 담는 큐

T = int(input())
for _ in range(T):
    w, h = map(int, input().split())
    building.clear()
    fires.clear()
    sanggeuns.clear()
    visit = [[0]*w for _ in range(h)]

    for y in range(h):
        building.append(list(input()))
        for x in range(w):
            if building[y][x] == '@':
                sanggeuns.append([x, y, 0])
                visit[y][x] = 1
                building[y][x] == '.'
            if building[y][x] == '*':
                fires.append([x, y])

    result = BFS()
    if result == 0:
        print("IMPOSSIBLE")
    else:
        print(result)
    