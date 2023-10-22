import sys 
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

T = int(input())
for _ in range(T): 
    N = int(input())
    graph = [[] for _ in range(N + 1)]
    M = int(input()) 
    for _ in range(M) :
        a, b = map(int, input().split()) 
        graph[a].append(b)
    
    if N != M - 1: 
        print("graph")
        continue 
    
    
    # 간선 수
    """
    Tree = N - 1
    """
    # 사이클 여부 
    """
    Tree: None 
    """