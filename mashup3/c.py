def verifica_parenteses(x):
    pilha = []
    for p in x:
        if(p == '('):
            pilha.append('(')
        elif(len(pilha)):
            pilha.pop()
        else:
            return False
    if(len(pilha) == 0):
        return True
    else:
        return False


n = int(input())
 
for i in range(n):
    a = input()
    first = a[0]
    a = a.replace(first, '(')
    last = a[-1]
 
    if last != '(':
        a = a.replace(last, ')')
    else:
        print("NO")
        continue
 
    w = [first, last]
    not_in = [i for i in ['A', 'B', 'C'] if i not in w][0]
    
    paberto = a.count('(')
    pfechado = a.count(')')
    if(paberto > pfechado):
        a = a.replace(not_in, ')')
    else:
        a = a.replace(not_in, '(')
    
    if(verifica_parenteses(a)):
        print("YES")
    else:
        print("NO")