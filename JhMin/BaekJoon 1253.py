''' 오답 코드
from itertools import combinations
from sys import stdin
input = stdin.readline


N = int(input().strip())
pocket = list(map(int, input().split()))


combination_list = list(combinations(pocket, 2))
count = 0
sum_list = []

for i in range(len(combination_list)):
    sum_list.append(sum(combination_list[i]))

sum_set = set(sum_list)

insertion = pocket & sum_set

print(len(insertion))
'''
# GPT 주석
# "잘 시도했어. 하지만 문제를 다시 한 번 꼼꼼히 읽어보자. 이 문제에서는 입력에 중복된 숫자가 있을 수 있고, 각 숫자는 인덱스가 다르게 존재할 수 있단다. 
# 그런데 set을 사용하면 중복이 제거되기 때문에, 중요한 정보를 잃게 돼. 또, 단순히 두 숫자의 조합만 고려하면 인덱스가 겹치지 않는다는 조건을 놓치게 돼. 
# 이런 문제에서는 입력 배열을 그대로 유지하고, 각 숫자마다 다른 두 숫자의 합으로 표현 가능한지 확인하는 것이 필요해. 그래서 두 포인터 기법 같은 효율적인 방법을 사용하면 더 좋단다.
# 항상 문제의 조건을 명확히 파악하고, 데이터의 특성(예: 중복, 인덱스 등)을 고려하여 적절한 자료구조와 알고리즘을 선택하는 습관을 기르도록 하자. 
# 이런 과정을 통해 더 깊이 있는 문제 해결 능력을 키울 수 있을 거야."


# 해답 코드
import sys
input = sys.stdin.readline

N = int(input().strip())
A = list(map(int, input().split()))
A.sort()  # 두 포인터를 위해 정렬

count = 0

for i in range(N):
    target = A[i]
    left, right = 0, N - 1
    while left < right:
        if left == i:  # target의 인덱스는 사용하면 안됨
            left += 1
            continue
        if right == i:
            right -= 1
            continue
        
        current_sum = A[left] + A[right]
        if current_sum == target:
            count += 1
            break
        elif current_sum < target:
            left += 1
        else:
            right -= 1

print(count)
