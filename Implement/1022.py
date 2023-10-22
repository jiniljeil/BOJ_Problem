import sys
input = sys.stdin.readline
N = 10000
DIV_N  = N // 2
r1, c1, r2, c2 = map(int, input().split())
r1, c1, r2, c2 = r1 + DIV_N, c1 + DIV_N, r2 + DIV_N, c2 + DIV_N 
# arr = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
arr = [[0 for _ in range(c1, c2 + 1)] for _ in range(r1, r2 + 1)]

L, D, R, U = 0, 1, 2, 3
dx = [-1, 0, 1, 0] 
dy = [ 0, 1, 0,-1]

cnt = 1 
y, x = DIV_N, DIV_N
dir = R 
n = 1
max_length = 0 
for i in range(1, (N + 1) * (N + 1) + 1): 
    if r1 <= y <= r2 and c1 <= x <= c2:  
        arr[y - r1][x - c1] = cnt
        max_length = max(max_length, i)
    cnt = cnt + 1
    ny, nx = y + dy[dir], x + dx[dir] 
    if not(DIV_N - n <= ny <= DIV_N + n and DIV_N - n <= nx <= DIV_N + n):# or arr[ny - r1][nx - c1] != 0: 
        dir = (dir + 1) % 4
    ny, nx = y + dy[dir], x + dx[dir]
    y, x = ny, nx
    if i == (2 * n) ** 2 + 2 * n + 1 :
        n = n + 1

for i in range(0, r2 - r1 + 1): 
    for j in range(0, c2 - c1 + 1): 
        f = "%"+ str(len(str(max_length))) + "d"
        print(f % (arr[i][j]), end=' ')
    print()

# for i in range(r1, r2 + 1): 
#     for j in range(c1, c2 + 1): 
#         print(arr[i][j], end=' ')
#     print()

"""
4999 -5000 5000 -4999
100010000  99970003 
100010001 100010002

-5000 -5000 -4999 -4999
100000001 100000000 
100000002  99960005

(Wrong)
4999 4999 5000 5000
 99980001  99980002 
100020000         0

(Right)
4999 4999 5000 5000
 99980001  99980002 
100020000 100020001
"""