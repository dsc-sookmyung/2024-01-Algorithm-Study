import sys
input = sys.stdin.readline

def check(phone_nums, N):
    for i in range(N-1):
        if phone_nums[i] == phone_nums[i+1][:len(phone_nums[i])]:
            print("NO")
            return 0
    print("YES")

T = int(input())
for _ in range(T):
    N = int(input())
    phone_nums = []
    for i in range(N):
        phone_nums.append(input().rstrip())
    phone_nums.sort()
    check(phone_nums, N)
