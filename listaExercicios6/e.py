from bisect import bisect_left

def check(k):
    for lista in dic.values():
        achou = True

        l, r = 1, k
        while(r <= len(s)):
            alvo = bisect_left(lista, l)
            if alvo != len(lista) and lista[alvo] <= r:
                l += 1
                r += 1
                continue
            
            achou = False
            break
        if achou:
            return True

    return False

s = input()
dic = {}
for i in range(len(s)):
    if s[i] not in dic:
        dic[s[i]] = [i + 1]
    else:
        dic[s[i]].append(i + 1)


l = 1
r = len(s)
while l <= r:
    mid = (l + r) // 2
    if check(mid):
        res = mid
        r = mid - 1
    else:
        l = mid + 1

print(res)
