# 2024 KAKAO WINTER INTERNSHIP
# 2. 도넛과 막대그래프

def solution(edges):
    answer = []
    dic = dict()
    max_val = 0
    for edge in edges:
        if max_val < max(edge):
            max_val = max(edge)
        if edge[1] not in dic:
            dic[edge[1]] = []
        if edge[0] not in dic:
            dic[edge[0]] = [edge[1]]
        else:
            dic[edge[0]].append(edge[1])
    visited = [0 for i in range(max_val+1)]

    for i in dic.values():
        for j in i:
            visited[j] = 1
    for i in dic:
        if len(dic[i]) <= 1:
            visited[i] = 1
    for i, val in enumerate(visited):
        if i != 0 and val == 0:
            created_node = i
    result = [0 for _ in range(4)]
    visited = [0 for _ in range(max_val+1)]

    def dfs(val):
        start = val
        visited[start] = 1
        stack = [val]
        while stack:
            cur = stack.pop()

            if len(dic[cur]) == 0:  # 막대 모양
                result[2] += 1
                return
            if len(dic[cur]) == 1:
                if visited[dic[cur][0]] == 0:
                    stack.append(dic[cur][0])
                else:
                    result[1] += 1
                    return
            if len(dic[cur]) == 2:
                result[3] += 1
                return

    result[0] = created_node
    for i in dic[created_node]:
        dfs(i)

    return result
