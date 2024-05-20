A, B = map(int, input().split())

#B의 제곱근의 최소 거의 소수는 B. 따라서 B의 제곱근보다 크면 거의 소수 모두 범위 바깥이다.
#따라서 2부터 ~ B의 제곱근까지만 소수를 찾으면 된다.
primeList = [True] * (int(B ** 0.5) + 1)
primeList[1] = False

for i in range(2, int(B ** 0.5) + 1):
    if primeList[i]:
        if i*i > int(B ** 0.5): 
            break
        for j in range(i**2, int(B ** 0.5) + 1, i): 
        #2*2, 2*3, 2*4, 2*5, 2*6 ...
        # ...
        #6*6, 6*7 (6*2, 6*3 ...)등은 미리 이전에 체크가 됨.
            primeList[j] = False
       
count = 0
for i in range(1, len(primeList)):
    if primeList[i]:
        res = i*i
        while True:
            if res < A:
                res *= i
                continue
            elif res > B:
                break
            else:
                res *= i
                count += 1
print(count)