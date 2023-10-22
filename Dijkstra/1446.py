import heapq, sys 
input = sys.stdin.readline

MAX = 10001
INF = 1e9 

def dijkstra(start): 
    queue = []
    heapq.heappush(queue, (0, start))
    dist[start] = 0 

    while queue: 
        curr_w, curr_v = heapq.heappop(queue)
        if curr_w > dist[curr_v]:
            continue 

        for next_v, next_w in graph[curr_v]:
            if dist[next_v] > curr_w + next_w:
                dist[next_v] = curr_w + next_w
                heapq.heappush(queue, (dist[next_v], next_v))

N, D = map(int, input().split()) 
dist = [INF] * (D+1) 

graph = [[] for _ in range(D + 1)]
for i in range(D):
    graph[i].append((i + 1, 1))

for i in range(N): 
    A, B, C = map(int, input().split())
    if B > D: 
        continue 
    graph[A].append((B, C))

dijkstra(0)
print(dist[D])
