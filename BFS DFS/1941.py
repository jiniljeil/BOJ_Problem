import sys, itertools 
import collections 
input = sys.stdin.readline

def bfs(locations):
    dx = [-1, 0, 1, 0] 
    dy = [ 0, 1, 0,-1] 

    q = collections.deque() 

    others = locations[1:]
    q.append(locations[0])

    while q: 
        y, x = q.pop()
        for k in range(4): 
            ny = y + dy[k]
            nx = x + dx[k] 

            if nx < 0 or ny < 0 or nx >= N or ny >= N : continue 

            if (ny, nx) in others: 
                others.remove((ny, nx))
                q.append((ny, nx)) 
                
    return True if not others else False

A = [list(input().strip()) for _ in range(5)] 
nums = [s for s in itertools.chain(*A)]
points = {5 * i + j: (i, j) for i in range(5) for j in range(5)}
ans = 0 
for arr in itertools.combinations(range(25), 7): 
    num_of_princes = sum([ 1 if nums[x] == 'S' else 0 for x in arr ])
    locations = [ points[x] for x in arr ]
    if num_of_princes >= 4 and bfs(locations): 
        ans += 1

print(ans)

"""
Wrong

def f(y, x, cnt, length, s): 
    global ans
    if length == 7 and cnt >= 4 : 
        ans = ans + 1
        print(s) 
    if length - cnt >= 4: return 

    for k in range(2): 
        nx = x + dx[k]
        ny = y + dy[k]

        if nx < 0 or nx >= N or ny < 0 or ny >= N : continue 
        if visited[ny][nx] : continue
        visited[ny][nx] = True
        f(ny, nx, cnt + 1 if A[ny][nx] == 'S' else cnt, length + 1, s + A[ny][nx])
        visited[ny][nx] = False

"""