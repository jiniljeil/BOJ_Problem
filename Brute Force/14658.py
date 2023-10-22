import sys 
input = sys.stdin.readline

C, R, L, K = map(int, input().split()) 
stars = [] 
ans = 0
for _ in range(K): 
    x, y = map(int, input().split())
    stars.append((y, x))

for y, x in stars:
    for k in range((L + 1) * (L + 1)):
        cnt = 0
        for oy, ox in stars:
            if y - L + k // (L + 1) <= oy <=  y + k // (L + 1) and x - L + k % (L + 1) <= ox <= x + k % (L + 1):
                cnt += 1            
        # for i in range(y - L + k // (L + 1), y + k // (L + 1) + 1): 
        #     for j in range(x - L + k % (L + 1), x + k % (L + 1) + 1): 
        #         if i < 0 or i >= R or j < 0 or j >= C: continue
        #         if (i, j) in stars: 
                    
        ans = max(ans, cnt)

print(len(stars) - ans)