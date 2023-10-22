import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def pre_to_post(preorder, N, minval, maxval, preIdx):
    if preIdx[0] == N: 
        return 

    if preorder[preIdx[0]] < minval or preorder[preIdx[0]] > maxval:
        return 

    val = preorder[preIdx[0]]
    preIdx[0] += 1

    pre_to_post(preorder, N, minval, val, preIdx)
    pre_to_post(preorder, N, val, maxval, preIdx) 
    print(val)

preorder = [] 
while True:
    try:
        preorder.append(int(input()))
    except:
        break
pre_to_post(preorder, len(preorder), -2**31, 2**31, [0])