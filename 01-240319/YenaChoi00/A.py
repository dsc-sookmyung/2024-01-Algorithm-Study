# 2024 KAKAO WINTER INTERNSHIP
# 1. 가장 많이 받은 선물

# 1

def solution(friends, gifts):
    answer = 0
    figure = []
    send_gift = {}
    result = {}

    for name in friends:
        # {'muzi': [0, 0, 0, 0, 0], ...}
        send_gift[name] = [0 for _ in range(len(friends))]
        figure = [0 for _ in range(len(friends))]
        result = [0 for _ in range(len(friends))]

    for i in range(len(gifts)):
        sender, receiver = gifts[i].split()
        send_gift[sender][friends.index(receiver)] += 1

        figure[friends.index(sender)] += 1
        figure[friends.index(receiver)] -= 1

    # 선물 교환 기록 비교
    for i in range(len(friends)):
        sender = friends[i]
        for k in range(len(friends)):
            receiver = friends[k]
            if i == k:  # 본인은 넘어감
                continue

            # 이중 for문이므로
            # 받을 경우만 계산!
            if send_gift[receiver][i] < send_gift[sender][k]:
                result[i] += 1
            # 선물을 주고받은 기록이 하나도 없거나(0으로 같다) 주고받은 수가 같다
            elif send_gift[receiver][i] == send_gift[sender][k]:
                if figure[i] > figure[k]:
                    result[i] += 1
    answer = max(result)
    # return answer
    return answer
