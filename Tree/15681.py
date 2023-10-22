import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline 

N, R, Q = map(int, input().split()) 
tree = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]
dp = [1 for _ in range(N + 1)]

def dfs(node):
    if visited[node] :
        return dp[node]
    visited[node] = True 
    for next in tree[node]:
        if visited[next]: continue 
        dp[node] = dp[node] + dfs(next)

    return dp[node]

for _ in range(N - 1): 
    a, b = map(int, input().split()) 
    tree[a].append(b)
    tree[b].append(a)

dfs(R)

for _ in range(Q): 
    U = int(input()) 
    print(dp[U])