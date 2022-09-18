# matriz = [
#     [0, 0, 0, 1],
#     [1, 1, 0, 0,],
#     [1, 0, 0, 1,],
#     [1, 0, 0, 1]
# ]

matriz = [
    [0, 0, 0, 1, 1],
    [1, 1, 0, 0, 1],
    [0, 0, 0, 1, 1],
    [0, 0, 0, 1, 0]
]

visitados = [[False for i in range(len(matriz[0]))] for i in range(len(matriz))]
res = []

for i in range(len(matriz)):
    for j in range(len(matriz[0])):
        if visitados[i][j]:
            continue

        if matriz[i][j] == 0:
            visitados[i][j] = True
            continue
        
        fila = []
        fila.append((i, j))
        tamanho = 0
        while fila:
            i, j = fila.pop(0)
            if matriz[i][j] == 0:
                visitados[i][j] == True
                continue

            visitados[i][j] = True
            tamanho += 1

            if i + 1 < len(matriz) and not(visitados[i+1][j]):
                fila.append((i+1, j))
                

            if i - 1 >= 0 and not(visitados[i-1][j]):
                fila.append((i-1,j))

            if j + 1 < len(matriz[0]) and not visitados[i][j+1]:
                fila.append((i,j+1))

            if j - 1 >= 0 and not(visitados[i][j-1]):
                fila.append((i, j-1))
        
        res.append(tamanho)

print(res)
