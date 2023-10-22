
"""
10 4 2
1 4 5 10
5 1

9 9 2
1 2 3 4 5 6 7 8 9
4 4
"""

import itertools, sys 
input = sys.stdin.readline

def f(m):
    tmp = 0 
    num_of_cut = C
    for i in range(K, -1, -1): 
        if arr[i] > m : return -1
        tmp += arr[i]
        if tmp > m:
            num_of_cut = num_of_cut - 1
            tmp = arr[i]
        if num_of_cut == 0:
            if cut[i] > m : return -1
            else: return cut[i]
        
    return cut[0]


L, K, C = map(int, input().split())
cut = sorted(map(int, input().split()))
cut.insert(0, 0)
cut.append(L) 

arr = [ cut[i] - cut[i - 1] for i in range(1, len(cut)) ]

cut.remove(0)

left = 0
right = L
ans_idx = 0 
ans = 1e9

while left < right: 
    mid = (left + right) // 2
    idx = f(mid)

    if idx >= 0 :
        if ans > mid: 
            ans = mid
            ans_idx = idx
        right = mid
    else:
        left = mid + 1
print(ans, ans_idx)
    