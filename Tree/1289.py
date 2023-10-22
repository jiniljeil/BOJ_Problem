import sys 
sys.setrecursionlimit(10**5) 
input = sys.stdin.readline

N = int(input())
tree = [[] for _ in range(N+1)]
answer = 0 
MOD = 1000000007
def dfs(curr, parent) : 
    global answer
    total = 1
    for next, weight in tree[curr]:
        if next == parent: continue 
        subtree = dfs(next, curr) * weight % MOD  
        answer = (answer + subtree * total) % MOD 
        total = (total + subtree) % MOD
    
    return total

for _ in range(N - 1): 
    A, B, W = map(int, input().split())
    tree[A].append((B, W)) 
    tree[B].append((A, W)) 

dfs(1, 0)
print(answer)

