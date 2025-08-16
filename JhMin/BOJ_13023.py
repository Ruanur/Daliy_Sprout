import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N, M = map(int, input().split())

dictionary = {}

for i in range(N):
    dictionary[i] = []

for i in range(M):
    t1, t2 = map(int, input().split())
    dictionary[t1].append(t2)
    dictionary[t2].append(t1)



visited = [False] * N
found_answer = False

def dfs(x, depth):
    global found_answer
    if depth == 4:
        found_answer = True
        return
    
    visited[x] = True

    for i in dictionary[x]:
        if visited[i]:
            continue
        dfs(i, depth + 1)
        if found_answer:
            return
    
    visited[x] = False

for i in range(N):
    dfs(i, 0)
    if found_answer:
        break

if found_answer:
    print(1)
else:
    print(0)
