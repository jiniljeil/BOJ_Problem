import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(curr): 
    for next in A[curr]:
        if visited[next] == 0: 
            visited[next] = curr
            dfs(next)

N = int(input())
visited = [0 for _ in range(N + 1)] 
A = [[] for _ in range(N + 1)]
for _ in range(N - 1): 
    a, b = map(int, input().split())
    A[a].append(b)
    A[b].append(a)

dfs(1) 

for i in range(2, N + 1): 
    print(visited[i])

