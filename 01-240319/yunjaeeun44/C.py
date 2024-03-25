from itertools import combinations, product
from bisect import bisect_left

def solution(dice):
    wins_dict = {}
    #주사위 조합
    combsA = list(combinations(range(len(dice)), len(dice)//2))
    for combA in combsA:
        combB = []
        for i in range(len(dice)):
            if i not in combA:
                combB.append(i)
                
        sumListA = [] #해당 주사위 조합에서 나올 수 있는 값
        sumListB = []
        for dice_product in product(range(6), repeat=len(dice)//2): #주사위면 중복 순열
            sumA = 0
            sumB = 0
            for i, j in zip(combA, dice_product):
                sumA += dice[i][j]
            for i, j in zip(combB, dice_product):
                sumB += dice[i][j]
            sumListA.append(sumA)
            sumListB.append(sumB)
        sumListB.sort() 
        
        wins = 0
        for sumA in sumListA:
            wins += bisect_left(sumListB, sumA)
        wins_dict[wins] = list(combA)
    
    max_key = max(wins_dict.keys())
    answer = []
    for x in wins_dict[max_key]:
        answer.append(x+1)
    
    return answer