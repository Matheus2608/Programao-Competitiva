# from collections import defaultdict
# def minWindow(s: str, t: str):
#     if len(t) > len(s):
#         return ""
#     matches = 0
#     dic1, dic2 = defaultdict(int), defaultdict(int)
    
#     for i in range(len(t)):
#         dic1[t[i]] += 1
        
#     res = len(s)    
#     l, r = 0, 0
#     while r < len(s):
#         dic2[s[r]] = 1 + dic2.get(dic1[s[r]], 0)
#         if dic2[s[r]] == dic1[s[r]]:
#             matches += 1

#         if matches == len(t):
#             res = min(res, r - l + 1)
#             if dic2[s[l]] == dic1[s[l]]:
#                 matches -=  1
#             dic2[s[l]] -= 1
#             l += 1
#             while dic2[s[l]] != dic1[s[l]]:
#                 dic2[s[l]] -= 1
#                 l += 1
#                 if matches == len(t):
#                     res = min(res, r - l + 1)
                
                    
#         r += 1
    
#     return res
# s, t = "ADOBECODEBANC", "ABC"
# minWindow(s, t)

def carFleet(target: int, position, speed):
    def x(posicao1, posicao2, speed1, speed2):
        if speed1 == speed2:
            if position1 == position2:
                return True, position1
            else:
                return False, -1
        diffp = posicao1 - posicao2
        diffs = speed2 - speed1
        div = diffp / diffs if diffs else diffp
        if div < 0:
            return False, -1
        else:
            posicao = posicao1 + speed1 * div
            if posicao <= target:
                return True, posicao
            else:
                return False, -1
        
    stack = [(position[0], speed[0])]
    for i in range(1, len(position)):
        encontram, pos = x(stack[-1][0], position[i], stack[-1][1], speed[i])
        if encontram:
            _, vel = stack.pop()
            vel = min(vel, speed[i])
            stack.append((pos, vel))
        else:
            stack.append((position[i], speed[i]))
    
    return len(stack)

print(carFleet(10,
[0,4,2],
[2,1,3]
))
