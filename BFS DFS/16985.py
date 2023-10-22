import sys, itertools, collections, copy
input = sys.stdin.readline

def bfs(A):
    steps = [[0, 0, -1], [0, 1, 0], [0, 0, 1], [0, -1, 0],
             [1, 0, 0], [-1, 0, 0]]
    visited = [[[-1] * 5 for _ in range(5)] for _ in range(5)]
    q = collections.deque()
    visited[0][0][0] = 0
    q.append((0, 0, 0))
    while q: 
        z, y, x = q.popleft() 

        if x == 4 and y == 4 and z == 4: 
            return visited[z][y][x]

        for dz, dy, dx in steps: 
            nx = x + dx
            ny = y + dy
            nz = z + dz

            if 0 <= nx <= 4 and 0 <= ny <= 4 and 0 <= nz <= 4:
                if A[nz][ny][nx] == 1 and visited[nz][ny][nx] == -1:
                    visited[nz][ny][nx] = visited[z][y][x] + 1
                    q.append((nz, ny, nx))

    return 1e9


def rotate(A, num):
    B = [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]
    for i in range(5):
        for j in range(5): 
            if num == 0: # 0
                B[i][j] = A[i][j] 
            elif num == 1: # 90
                B[i][j] = A[4 - j][i]
            elif num == 2: # 180
                B[i][j] = A[4 - i][4 - j]
            elif num == 3: # 270 
                B[i][j] = A[j][4 - i]
    return B

def solve(A):
    C = [[a,b,c,d,e] for a in range(4) for b in range(4)
        for c in range(4)for d in range(4)for e in range(4)]
    
    result = 1e9
    for transition in itertools.permutations(range(5), 5):
        for rotation in C: 
            D = [rotate(A[transition[x]], rotation[x]) for x in range(5) ]

            if D[0][0][0] == 1 and D[4][4][4] == 1:
                result = min(result, bfs(D))
    if result == 1e9:
        return -1
    else :
        return result

A = [] 

for _ in range(5):
    t = [list(map(int, input().split())) for _ in range(5)] 
    A.append(t)

print(solve(A))           