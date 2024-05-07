#백준 3273번 두 수의 합

#n 입력받기
n=int(input())
#수열 입력받기
data=list(map(int,input().split()))
#x 입력받기
x=int(input())
data.sort() #수열 오름차순으로 정렬
answer=0

front=0 #앞쪽 포인터
back=n-1 #뒤쪽 포인터

while front<back:
  #두 수를 더했을 때 x가 나온 경우
  if data[front]+data[back]==x:
    answer+=1
  #두 수를 더했을 때 x보다 작은 경우
  elif data[front]+data[back]<x:
    front+=1 #포인터 뒤로 이동
    continue
  #포인터 앞으로 이동
  back-=1
    
print(answer)