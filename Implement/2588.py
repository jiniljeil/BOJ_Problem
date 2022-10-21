a = input() 
b = input()
c = [] 
for i in range(len(b) - 1, -1, -1):
    i_a = int(a) 
    i_b = int(b[i]) 
    print(i_a * i_b) 
    c.append(i_a * i_b)

s = 0 
for i in range(len(c)): 
    s = s + int(str(c[i]) + '0' * i) 
print(s)