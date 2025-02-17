
# dfs(깊이 우선 탐색 - 재귀 방식)
def dfs(graph, start, visited=None):
    # graph: {정점: [연결된 정점들]} 형태의 딕셔너리
    # start: 시작 정점
    # visited: 방문한 정점을 저장하는 집합
    if visited is None:
        visited = set()

    visited.add(start)
    print(start, end=" ")
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
    return visited

# 사용 예시:
# graph = {
#   1: [2, 3]
#   2: [1, 4, 5],
#   3: [1],
#   4: [2]
#   5: [2]
# }
# dfs(graph, 1)


# bfs(넓이 우선 탐색 - 반복 방식)
from collections import deque

def bfs(graph, start):
    # graph: {정점: [연결된 정점들]} 형태의 딕셔너리
    # start: 시작 정점
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        vertex = queue.popleft()
        print(vertex, end=" ")
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# 사용 예시:
# bfs(graph, 1)


# binary search(이진 탐색)
def binary_search(arr, target):
    # arr: 정렬된 리스트
    # target: 찾고자 하는 값
    # 반환: target의 인덱스, 없으면 -1 반환
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid # target 발견시 인덱스 반환
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

# 사용 예시:
# idx = binary_search([1, 3, 5, 7, 9], 7)


# Two Pointer(투 포인터)
def two_pointer(arr, target):
    # arr: 정렬된 리스트
    # target: 두 수의 합으로 찾고자 하는 값
    # 반환: 조건을 만족하는 (왼쪽 인덱스, 오른쪽 인덱스) 튜플, 없으면 None 반환
    left, right = 0, len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return left, right
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    return None

# 사용 예시:
# result = two_pointer([1, 2, 3, 4, 6], 6)


# Dijkstra(최단 경로 알고리즘)
import heapq

def dijkstra(graph, start):
    # graph: {정점: [(인접 정점, 가중치), ...]} 형태의 딕셔너리
    # start: 시작 정점
    # 반환: 시작 정점으로부터 각 정점까지의 최단 거리 딕셔너리
    INF = float('inf')
    distances = {node: INF for node in graph}
    distances[start] = 0
    heap = [(0, start)]

    while heap:
        current_dist, current_node = heapq.heappop(heap)
        if current_dist > distances[current_node]:
            continue
        for neighbor, weight in graph[current_node]:
            distance = current_dist + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(heap, (distance, neighbor))
    return distances

# 사용 예시:
# graph = {
#     'A': [('B', 2), ('C', 5)],
#     'B': [('A', 2), ('C', 1), ('D', 4)],
#     'C': [('A', 5), ('B', 1), ('D', 1)],
#     'D': [('B', 4), ('C', 1)]
# }
# print(dijkstra(graph, 'A'))


# union-find(disjoint set union)
def find(parent, x):
    # x의 루트 노드를 찾음(경로 압축 적용)
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    # 두 원소 a, b를 포함하는 집합을 합침
    a_root = find(parent, a)
    b_root = find(parent, b)
    if a_root < b_root:
        parent[b_root] = a_root
    else:
        parent[a_root] = b_root

# 사용 예시:
# parent = {i: i for i in range(1, 6)}
# union(parent, 1, 2)
# union(parent, 3, 4)
# union(parent, 2, 3)
# print(find(parent, 4))


# backtraking(백트래킹 - 부분집합 구하기 예시)
def backtrack(result, temp, nums, start):
    # result: 결과를 담을 리스트
    # temp: 현재까지 선택된 원소들의 리스트
    # nums: 입력 리스트
    # start: 탐색 시작 인덱스
    result.append(temp.copy())
    for i in range(start, len(nums)):
        temp.append(nums[i])
        backtrack(result, temp, nums, i + 1)
        temp.pop()

def subsets(nums):
    # nums의 모든 부분집합을 반환
    result = []
    backtrack(result, [], nums, 0)
    return result

# 사용 예시:
# print(subsets)([1, 2, 3]))


# memoization
def memoize(func):
    cache = {}
    def wrapper(*args):
        if args in cache:
            return cache[args]
        result = func(*args)
        cache[args] = result
        return result
    return wrapper

@memoize
def expensive_function(x, y):
    # 복잡한 계산 예시
    return x * y + x - y

# 사용 예시:
# print(expensive_function(5, 3))


# DP(bottom-up)
def fib_bottom_up(n):
    if n < 2:
        return n
    dp = [0] * (n + 1)
    dp[0], dp[1] = 0, 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]

# 사용 예시:
# print(fib_bottom_up(10))
# 장점: 반복문 기반, 메모리 사용 최적화
# 단점: 문제 구조 파악 필요(하위 문제 순서 정확히 파악 후 반복문 구성), 직관성 떨어짐


# DP(top-down, memoization)
def fib_top_down(n, memo={}):
    if n in memo:
        return memo[n]
    if n < 2:
        return n
    memo[n] = fib_top_down(n - 1, memo) + fib_top_down(n - 2, memo)
    return memo[n]

# 사용 예시:
# print(fib_top_down(10))
# 장점: 코드가 직관적이고 간결, 불필요한 계산을 방지
# 단점: 재귀 깊이 제한 문제(파이썬), 재귀 호출 오버헤드
