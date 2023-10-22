import sys, itertools, collections
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [ 0, 1, 0,-1]
N, M, G, R = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
gr = ['G'] * G + ['R'] * R
ans = 0 

grounds = [] 
for i in range(N):
    for j in range(M): 
        if arr[i][j] == 2 : 
            grounds.append((i, j))

def bfs(red, green): 
    q = collections.deque() 
    visited = [[0] * M for _ in range(N)]
    cnt = 0 

    for y, x in green:
        q.append((y, x))
        visited[y][x] = -1 
    
    for y, x in red:
        q.append((y, x))
        visited[y][x] = 1

    while q :
        y, x = q.popleft() 

        for k in range(4): 
            nx = x + dx[k]
            ny = y + dy[k] 

            if nx < 0 or ny < 0 or nx >= M or ny >= N or arr[ny][nx] == 0: 
                continue
            # first visit
            if visited[ny][nx] == 0:
                if visited[y][x] < 0: 
                    visited[ny][nx] = visited[y][x] - 1
                    q.append((ny, nx))
                elif 0 < visited[y][x] < 1e9: 
                    visited[ny][nx] = visited[y][x] + 1
                    q.append((ny, nx)) 
            
            # second visit (different color)
            # Because green color is put before red color is put, check + 1 not - 1
            if visited[ny][nx] + visited[y][x] + 1 == 0:
                visited[ny][nx] = 1e9
                cnt += 1
    return cnt

for comb in itertools.combinations(grounds, G + R): 
    for color in set(itertools.permutations(gr)):
        red, green = [], []
        for k in range(G+R):
            if color[k] == 'R':
                red.append(comb[k])
            else:
                green.append(comb[k])
        ans = max(ans, bfs(red, green))

print(ans)