# BOJ 13413

from collections import deque

t = int(input())


def solution(N, arr, answer):
    count = 0
    change = deque()    # 바꿔야 하는 말을 담을 스택

    for i in range(N):
        if arr[i] != answer[i]:
            if change:
                piece = change.pop()
                if piece != arr[i]:     # 바꿔치기가 가능하면
                    count += 1
                else:
                    change.append(piece)    # 꺼낸 말 다시 넣어주기
                    change.append(arr[i])   # 이번 말도 추가해주기
            else:
                change.append(arr[i])

    count += len(change)
    # 바꿔치기가 안되고 남아있는 말들은 뒤집기밖에 못한다. 결국 남아있는 말들은 전부 W이거나 전부 B임

    return count


for _ in range(t):
    n = int(input())
    arr = input()
    answer = input()

    print(solution(n, arr, answer))
