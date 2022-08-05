#vamos usar python para fazer esse not pq ne deus me livre

n = int(input())

num_binario = bin(n)[2:] #para tirar o q nao presta na representacao
not_num_binario = ''

for bit in num_binario:
    if bit == '0':
        not_num_binario += '1'
    else:
        not_num_binario += '0'

not_num_binario = int(not_num_binario, 2)

print(str(n) + " " + str(not_num_binario))

