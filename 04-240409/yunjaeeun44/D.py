N = int(input())
arr = list(map(int, input().split()))
x = int(input())

arr.sort()
left, right = 0, N-1
answer = 0

while(left < right):
    if arr[left] + arr[right] == x:
        answer += 1
        left += 1
        right -= 1
    elif arr[left] + arr[right] > x:
        right -= 1
    elif arr[left] + arr[right] < x:
        left += 1

print(answer)