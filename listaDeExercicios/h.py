def soma(atual, string):
    print(string)
    tmp = int(string[atual]) + 1
    while(tmp == 0):
        string = string[:atual] + '0' + string[atual]
        atual -= 1
        tmp = int(string[atual]) + 1
    print(string[atual])
    string = string[:atual] + str(tmp) + string[atual]


def recursao(string):
    for atual in range(len(string) - 1, 0, -1):
        for anterior in range(atual - 1, 0, -1):
            if(string[atual] == string[anterior]):
                soma(atual, string)
                recursao(string)

x = int(input()) + 1
string = str(x)
recursao(string)




           