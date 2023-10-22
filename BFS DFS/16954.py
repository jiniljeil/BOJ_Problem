import sys, collections
input = sys.stdin.readline

def bfs(): 
    global W
    ans = 0
    # diff (range)
    dx = [0, -1, -1, 0, 1, 1, 1, 0, -1]
    dy = [0,  0, -1,-1,-1, 0, 1, 1,  1]
    # diff (visited)
    visited = set()
    q = collections.deque()
    q.append((7, 0))

    while q: 
        for _ in range(len(q)):
            # diff
            y, x = q.popleft()
            if (y, x) in W:
                continue
            if y == 0 and x == 7: 
                ans = 1
                break
            for k in range(9): 
                nx = x + dx[k]
                ny = y + dy[k]

                if 0 <= nx <= 7 and 0 <= ny <= 7 and not (ny, nx) in visited and not (ny, nx) in W:
                    visited.add((ny, nx)) 
                    q.append((ny, nx))
        if W:
            visited = set() 
        
        NW = set() 
        for y, x in W:
            if y < 7: 
                NW.add((y + 1, x))
        W = NW 

    print(ans)

A = [list(input().rstrip()) for _ in range(8)] 
W = [(i, j) for i in range(8) for j in range(8) if A[i][j] == '#' ]
bfs()

# print(B)