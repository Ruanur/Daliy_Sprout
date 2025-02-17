# 1. 빠른 입출력
import sys
input = sys.stdin.readline

n = int(input().strip())
arr = list(map(int, input().split()))


# 2. 기본 자료구조와 컬렉션
# (1) - 리스트 컴프리헨션, ..
squares = [x * x for x in range(10)]
square_dict = {x: x * x for x in range(10)}
square_set = {x * x for x in range(10)}

# (2) - collections 모듈: deque, defaultdict, counter
from collections import deque
dq = deque()
dq.append(1)
dq.popleft()

from collections import defaultdict
dd = defaultdict(int)
dd['a'] += 1

from collections import Counter
cnt = Counter([1, 2, 2, 3])
print(cnt) # Counter({2: 2, 1: 1, 3: 1})


# 3. 함수형 프로그래밍 문법
# (1) - lambda 함수
f = lambda x: x * x
print(f(5))

# (2) - map, filter, reduce
# map: 리스트의 각 원소에 함수를 적용
# filter: 조건을 만족하는 원소만 걸러냄
# reduce: 누적 연산(functools 모듈에서 제공)
nums = [1, 2, 3, 4]
squares = list(map(lambda x: x ** 2, nums))

evens = list(filter(lambda x: x % 2 == 0, nums))

from functools import reduce
product = reduce(lambda a, b: a * b, nums)


# 4. 정렬과 이진 탐색
# (1) - 정렬(stable sort)
arr = [3, 1, 4, 1, 5]
sorted_arr = sorted(arr) # 원본을 변경하지 않고 정렬
arr.sort() # 제자리 정렬

data = [("apple", 3), ("banana, 2"), ("cherry", 5)]
# 두 번째 요소(숫자)를 기준으로 정렬
data.sort(key=lambda x: x[1])

# (2) - 이진 탐색(bisect 모듈)
import bisect
arr = [1, 3, 4, 4, 6]
idx = bisect.bisect_left(arr, 4) # 왼쪽 기준
idx = bisect.bisect_right(arr, 4) # 오른쪽 기준


# 5. 힙(Heap)과 우선순위 큐
# heapq 모듈: 최소 힙 제공, 우선순위 큐 구현 시 사용
import heapq
heap = []
heapq.heappush(heap, 3)
heapq.heappush(heap, 1)
heapq.heappush(heap, 2)
print(heapq.heappop(heap)) # 1 (가장 작은 값)

# 최대 힙 구현: 부호를 반대로 저장
max_heap = []
heapq.heappush(heap, -3)
heapq.heappush(heap, -1)
heapq.heappush(heap, -2)
print(-heapq.heappop(max_heap)) # 3 (가장 큰 값)


# 6. itertools와 functools 활용
# (1) - itertools 모듈: 반복 가능한 자료를 다루는 다양한 함수 제공
import itertools
# 순열: 모든 순서대로의 배열 생성
perms = list(itertools.permutations([1, 2, 3]))
# 조합: 순서에 상관없이 선택
combs = list(itertools.combinations([1, 2, 3, 4], 2))
# 데카르트 곱
prod = list(itertools.product([1, 2], ['a', 'b']))

# (2) - fuctools 모듈: 함수 관련 도구 제공
# Iru_cache: 메모이제이션을 위한 데코레이터
from functools import lru_cache

@lru_cache(maxsize=None)
def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)
# reduce: 앞서 설명한 reduce 함수도 여기에 속함


# 7. 수학 관련 내장 함수
# math 모듈: 다양한 수학 함수와 상수 제공
import math
print(math.sqrt(16))
print(math.gcd(12, 8))
print(math.factorial(5))
print(math.pi)


# 8. 재귀와 재귀 제한
# 기본 재귀 깊이 제한이 낮을 수 있으므로, 필요 시 조정
import sys
sys.setrecursionlimit(10**6)


# 9. 기타 유용한 기능들
# enumerate: 인덱스와 함께 반복
for idx, value in enumerate(['a', 'b', 'c']):
    print(idx, value)

# zip: 여러 리스트를 동시에 순회
a = [1, 2, 3]
b = ['x', 'y', 'z']
for num, char in zip(a, b):
    print(num, char)

# reverse: 역순 순회
for x in reversed([1, 2, 3]):
    print(x)
