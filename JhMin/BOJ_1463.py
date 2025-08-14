import sys
limit = sys.setrecursionlimit(100000000)

dp = [100000] * 1000006

def dfs(x):
    if x == 1:
        return
    if x % 3 == 0:
        nx = x // 3
        if dp[nx] > dp[x] + 1:
            dp[nx] = dp[x] + 1
            dfs(nx)

    if x % 2 == 0:
        nx = x // 2
        if dp[nx] > dp[x] + 1:
            dp[nx] = dp[x] + 1
            dfs(nx)
    
    nx = x - 1
    if dp[nx] > dp[x] + 1:
            dp[nx] = dp[x] + 1
            dfs(nx)

n = int(input())

dp[n] = 0

dfs(n)

print(dp[1])
