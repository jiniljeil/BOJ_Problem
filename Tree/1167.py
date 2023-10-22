import sys, collections 
sys.setrecursionlimit(10**5+1)
input = sys.stdin.readline

V = int(input())
graph = [[] for _ in range(V + 1)] 
visited = [ -1 for _ in range(V+1)]
def dfs(node) :
    for next, dist in graph[node]: 
        if visited[next] == -1: 
            visited[next] = visited[node] + dist
            dfs(next)

for _ in range(V): 
    a = list(map(int, input().split()))
    node = 0 
    for k in a[1:-1]:
        if node != 0: 
            graph[a[0]].append((node, k))
            node = 0 
            continue
        node = k
visited[1] = 0
dfs(1)
max_length = 0 
max_node = 0
for i in range(1, V+1):
    if visited[i] > max_length:
        max_length = visited[i] 
        max_node = i 
visited = [-1 for _ in range(V+1)]
visited[max_node] = 0 
dfs(max_node) 
print(max(visited))

