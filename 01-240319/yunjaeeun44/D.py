from collections import deque

def check(deck1, deck2, target):
    for card in deck1:
        if target - card in deck2:
            deck1.remove(card)
            deck2.remove(target-card)
            return True
    return False
    

def solution(coin, cards):
    answer = 1
    hands = cards[:len(cards)//3]
    deck = deque(cards[len(cards) // 3:])
    draws = []
    
    while coin >=0 and deck:
        draws.append(deck.popleft())
        draws.append(deck.popleft())
        
        if check(hands, hands, len(cards) + 1):
            pass
        elif coin >= 1 and check(hands, draws, len(cards) + 1):
            coin -= 1
        elif coin >= 2 and check(draws, draws, len(cards) + 1):
            coin -= 2
        else:
            break
        answer += 1
    return answer