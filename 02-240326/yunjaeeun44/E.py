N, K = map(int, input().split())
nums = list(map(int, input().split()))
left, right, answer = 0, 0, 0
dic = {}

while right < N:
    if not dic.get(nums[right]):
        dic[nums[right]] = 1
        right += 1
    elif dic.get(nums[right]) < K:
        dic[nums[right]] = dic[nums[right]] + 1
        right += 1
    else:
        dic[nums[left]] = dic[nums[left]] - 1
        left += 1
    answer = max(answer, right - left)
print(answer)
        