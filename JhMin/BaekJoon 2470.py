''' 오답 코드
import sys
input = sys.stdin.readline


N = int(input().strip())
compose_liquid = list(map(int, input().split()))

compose_liquid.sort()

left = 0
right = len(compose_liquid) - 1
temp = compose_liquid[left] + compose_liquid[right]
temp_abs = abs(temp)
index_list = [left, right]

while left < right:
    if abs(compose_liquid[left] + compose_liquid[right]) < temp_abs:
        temp = compose_liquid[left] + compose_liquid[right]
        temp_abs = abs(temp)
        index_list = [left, right]

    elif compose_liquid[left] + compose_liquid[right] < temp:
        right -= 1
        continue

    left += 1
        
    
print(f"{compose_liquid[index_list[0]]} {compose_liquid[index_list[1]]}")
'''


# ChatGPT 주석
# 우선, 코드 논리가 전반적으로 잘 작성되었습니다. 배열을 정렬하고 두 포인터를 사용하여 두 수의 합을 검사하는 방식은 좋습니다. 
# 그러나 while 루프에서 left += 1과 right -= 1을 조건에 따라 제어하는 것이 좀 혼동될 수 있습니다. 
# left와 right의 위치 업데이트는 조건문 안에서 명확히 분리하여 더 직관적이도록 작성할 수 있습니다. 
# 또한 elif 구문은 불필요할 수 있다는 점을 고려해 볼 수 있습니다.

# 이 코드는 두 개의 액체가 합해서 0에 가장 가까운 값을 찾는 목표로 작성되었습니다.
# while left < right: 조건은 인덱스 중복이 없으므로 적합합니다.
# temp와 temp_abs를 사용해 현재까지의 최적 합을 저장하는 방식은 잘 구현됐습니다.

# 문제는 포인터 이동에 있습니다. 
# 현재는 elif compose_liquid[left] + compose_liquid[right] < temp: 조건문 내에서 right -= 1 후 continue가 사용되고 있는데, 이 부분은 수정이 필요합니다. 
# 올바른 수정은 합이 0보다 작으면 left += 1, 그렇지 않으면 right -= 1 입니다.

# 또한 현재의 합이 0인 경우 즉시 종료하는 부분이 갱신되지 않아 다소 비효율적인 점도 개선할 수 있습니다.


# 해답 코드
import sys
input = sys.stdin.readline

N = int(input().strip())
compose_liquid = list(map(int, input().split()))
compose_liquid.sort()

left, right = 0, N - 1
best = float('inf')
ans_left, ans_right = left, right

while left < right:
    current_sum = compose_liquid[left] + compose_liquid[right]
    
    if abs(current_sum) < best:
        best = abs(current_sum)
        ans_left, ans_right = left, right
        
        if current_sum == 0:
            break  # 더 이상 0에 가까운 값을 찾을 수 없음

    if current_sum < 0:
        left += 1
    else:
        right -= 1

print(compose_liquid[ans_left], compose_liquid[ans_right])
