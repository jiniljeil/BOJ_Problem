"""
실수한 부분
- 그룹이 연속적으로 입력될 것이라는 착각 
3
1  
1 3
Wrong)
2
1
2
3
Answer)
2
1 
2

- 정렬 안하고 출력 
"""
import sys, collections
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

N = int(input()) 
graph = [[] for _ in range(N + 1)]
distance = [ 0 for x in range(N + 1)]
M = int(input()) 

def bfs(start): 
    q = collections.deque()
    visited = [False for _ in range(N + 1)]  
    q.append((start, 0))
    visited[start] = True 
    max_dist = 0 
    while q:
        curr, dist = q.popleft() 
        if dist > max_dist :
            max_dist = dist

        for next in graph[curr]: 
            if visited[next]: continue
            visited[next] = True
            q.append((next, dist + 1)) 
    return max_dist

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b) 
    graph[b].append(a) 

num_of_groups = 0 
leaders = [] 
for i in range(1, N + 1): distance[i] = bfs(i)

visited = [False for _ in range( N + 1 )]

for v in range(1, N + 1):
    if visited[v] : continue 
    groups = [] 
    q = collections.deque() 
    q.append(v)
    visited[v] = True
    num_of_groups += 1
    while q: 
        x = q.popleft() 
        groups.append(x)
        for nx in graph[x]: 
            if visited[nx] != 0 : continue
            visited[nx] = True
            q.append(nx) 
    dist = 1e9
    leader = 0  
    for node in groups: 
        if distance[node] < dist: 
            dist = distance[node]
            leader = node
    leaders.append(leader)

print(num_of_groups)
for leader in sorted(leaders):
    print(leader)