import sys, collections
input = sys.stdin.readline

N = int(input()) 
tree = [[None, None] for _ in range(N + 1)]
indegree = [0 for _ in range(N + 1)]
layers = collections.defaultdict(list)
count = 1

def inorder(node, layer): 
    global count
    left, right = tree[node]
    if left != -1 : inorder(left, layer + 1)
    layers[layer].append(count)
    count += 1
    if right != -1: inorder(right, layer + 1) 

for _ in range(N): 
    parent, left, right = map(int, input().split()) 
    tree[parent][0] = left
    tree[parent][1] = right
    if left != -1: indegree[left] += 1 
    if right != -1:  indegree[right] += 1

root = -1
for i in range(1, N + 1): 
    if indegree[i] == 0: 
        root = i 
        break

inorder(root, 1)

level, width = 0, 0
for key in sorted(layers):
    layer = layers[key]
    w = max(layer) - min(layer) + 1 
    if width < w: 
        width = w 
        level = key 

print(level, width)

