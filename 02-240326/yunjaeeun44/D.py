import sys
#input = sys.stdin.readline

S = input()
duck = ['q','u','a','c','k']
ducks = [[]]
valid = True

def main():
    for sound in S:
        put = False
        idx = duck.index(sound)
        for i in ducks:
            if len(i)%5 == idx:
                i.append(sound)
                put = True
                break
        if put == False and idx == 0:
            ducks.append(['q'])
            put = True
        elif put == False:
            print(-1)
            return 0
    
    for i in ducks:
        if len(i)%5 != 0:
            print(-1)
            return 0
    print(len(ducks))

main()