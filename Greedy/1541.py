expression = str(input())

expr_sp = expression.split('-')

result = 0
for i in range(len(expr_sp)):
    if i == 0: 
        tmp = expr_sp[0].split('+')
        for j in tmp:
            result += int(j)
    else:
        s = 0
        tmp = expr_sp[i].split('+')
        for j in tmp:
            s += int(j)
        result -= s

print(result)
