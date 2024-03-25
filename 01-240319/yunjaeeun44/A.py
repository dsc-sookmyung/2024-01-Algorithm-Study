def solution(friends, gifts):
    givers = {}
    receivers = {}
    score = {}
    answer = {}
    #givers, receivers
    for friend in friends:
        givers[friend] = []
        receivers[friend] = []
        answer[friend] = 0
    for gift in gifts:
        giver, receiver = gift.split()
        givers[giver].append(receiver)
        receivers[receiver].append(giver)
    #score
    for friend in friends:
        score[friend] = len(givers.get(friend))-len(receivers.get(friend))
    #answer
    for friend in friends:
        #두 사람이 선물을 주고받은 기록 체크
        for other in friends:
            if other == friend:
                continue
            #선물을 주고받은 기록이 서로 같아서 선물 지수 체크
            if givers[friend].count(other) == givers[other].count(friend):
                if score[friend] > score[other]:
                    answer[friend] += 1
            #선물을 주고받은 기록이 서로 다름
            elif givers[friend].count(other) > givers[other].count(friend):
                    answer[friend] += 1
    return max(answer.values())