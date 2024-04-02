# 2024 KAKAO WINTER INTERNSHIP
# 3. 주사위 고르기

from itertools import combinations


def binary_search(target, case):
    low = 0
    high = len(case) - 1

    while low <= high:
        mid = (low + high) // 2

        if case[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return low


def simulate(case, dice, idx, now, out):
    if idx == len(case):
        out.append(now)
        return

    for d in dice[case[idx]]:
        simulate(case, dice, idx + 1, now + d, out)


def solution(dice):
    answer = []

    half = len(dice) // 2
    selected_cases = list(combinations(list(range(len(dice))), half))

    sum_cases = {}
    for idx, case in enumerate(selected_cases):
        out = []
        simulate(case, dice, 0, 0, out)
        out.sort()
        sum_cases[idx] = out

    bestest_sum = 0
    for key, value in sum_cases.items():
        now_case = value
        other_case = sum_cases[len(selected_cases) - key - 1]

        temp_sum = 0
        for c in now_case:
            temp_sum += binary_search(c, other_case)

        if temp_sum > bestest_sum:
            bestest_sum = temp_sum
            best_case = selected_cases[key]
            answer = list(map(lambda x: x + 1, sorted(best_case[:])))

    return answer
