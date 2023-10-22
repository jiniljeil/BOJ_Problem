import collections 
import itertools 
import sys 
import copy 

input = sys.stdin.readline
dx = [-1,0,1,0]
dy = [ 0,1,0,-1]

N, M = map(int, input().split()) 
A = [list(map(int, input().split())) for _ in range(N)]

virus = set()
for i in range(N): 
    for j in range(N): 
        if A[i][j] == 2:
            virus.add((i, j)) 
        
result = 1e9 
check4 = False # if total visit or not 
for comb in itertools.combinations(virus, M):
    q = collections.deque()
    B = copy.copy(A)

    visited = [[-1] * N for _ in range(N)]
    for i in range(N):
        for j in range(N): 
            if (i, j) in comb:  
                q.append((i, j, False))
                visited[i][j] = 0

    tmp = 0 
    check2 = False # if visit the zero or not
    while q: 
        y, x, check = q.popleft() 
        if check and A[y][x] != 2:
            check2 = True # if visit the zero or not
            tmp = max(tmp, visited[y][x])
        for k in range(4):
            ny = y + dy[k]
            nx = x + dx[k] 

            if ny < 0 or nx < 0 or ny >= N or nx >= N: continue
            if visited[ny][nx] >= 0 or A[ny][nx] == 1: continue

            visited[ny][nx] = visited[y][x] + 1
            if A[ny][nx] == 0:
                q.append((ny, nx, True))
            else:
                q.append((ny, nx, check)) 

    check3 = True # if total visit or not 
    for i in range(N):
        for j in range(N):
            if A[i][j] == 0 and visited[i][j] == -1:
                check3 = False
                break
        if not check3:
            break
    if check3: 
        check4 = True # if total visit or not
        if check2 :
            result = min(result, tmp)

if result == 1e9 :
    if check4: # if total visit or not
        print(0)
    else: 
        print(-1)
else: 
    print(result)

