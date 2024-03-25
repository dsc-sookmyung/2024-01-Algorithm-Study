from collections import Counter

def solution(edges):
    answer = [0, 0, 0, 0]
    dotChecks = {}
    for start, end in edges:
        if dotChecks.get(start) == None:
            dotChecks[start] = [0, 0]
        if dotChecks.get(end) == None:
            dotChecks[end] = [0, 0]
        dotChecks[start][0] += 1
        dotChecks[end][1] += 1
    for key, check in dotChecks.items():
        if check[0] >=2 and check[1] == 0: #생성한 정점
            answer[0] = key
        elif check[0]==2 and check[1]>=2: #8자 그래프(생성된 정점에서 나온 간선의 도착점일 경우 존재)
            answer[3] += 1
        elif check[0]==0:
            answer[2] += 1
    answer[1] = dotChecks[answer[0]][0] - answer[2] - answer[3]
    return answer