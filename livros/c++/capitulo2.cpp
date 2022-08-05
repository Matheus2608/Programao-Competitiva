
#include <iostream>
#include <stdlib.h> 
using namespace std;
// Um protótipo é uma declaração que especifica a interface de uma função. Nessa declaração devem 
// constar o tipo da função, seu nome e o tipo de cada um de seus parâmetros. Ao contrário da norma 
// C-ANSI, que estabelece que uma função declarada com
// uma lista de argumentos vazia – f() – pode receber qualquer número de parâmetros, de
// quaisquer tipos, em C++, uma tal declaração equivale a f(void). Uma função cujo tipo
// não seja void deve, obrigatoriamente, devolver um valor através do comando return. 

int f(int,int); // a função f recebe dois parâmetros int e retorna int
double g(char,int); // a função g recebe um char e um int e retorna double

// A presença do nome de um parâmetro no protótipo é opcional; entretanto, 
// recomendase que ele conste da declaração sempre que isso aumentar a legibilidade do programa. 

int pesquisa(char *lista[],int tam, char *nome);
void cursor(int coluna, int linha); 

// Além da passagem por valor, C++ também permite passar parâmetros por referência.
// Quando usamos passagem por referência, o parâmetro formal declarado na função é na
// verdade um sinônimo do parâmetro real que foi passado a ela. Assim, qualquer alteração realizada no parâmetro formal ocorre também no parâmetro real. Para indicar que
// um parâmetro esta sendo passado por referência, devemos usar o operador & prefixado
// ao seu nome. 

void troca(int &, int &); // parâmetros serão passados por referência
void main(void)
{
 int x=5, y=7;
 cout << "Antes : x=" << x << ", y=" << y << endl;
 troca(x,y);
 cout << "Depois: x=" << x << ", y=" << y << endl;
} 

void troca(int &a, int &b) // parâmetros recebidos por referência
{
 int x = a;
 a = b;
 b = x;
} 

// A chamada de uma função com parâmetros de referência é muito simples. 
// Essa facilidade aumenta a legibilidade e a potência da linguagem; mas deve ser usada com
// cautela, já que não há proteção ao valor do parâmetro real que é transmitido à função. 

// O uso da palavra reservada const na declaração dos parâmetros de referência permite
// anular o risco de alteração do parâmetro real, ao mesmo tempo em que evita que seu
// valor tenha que ser duplicado na memória, o que ocorreria numa passagem por valor. 

struct Ficha {
 char nome[20];
 char email[30];
};
void exibe(const Ficha &f)
{
 cout << f.nome << ": " << f.email << endl;
}
void main(void)
{
 Ficha usr = { "Silvio", "slago@ime.usp.br" };
 exibe(usr);
} 

// Referências e ponteiros podem ser combinados, sem nenhum problema:

bool abrir(FILE *&arquivo, char *nome)
{
 if( (arquivo=fopen(nome,"r"))==NULL ) // se arquivo não existe
 arquivo=fopen(nome,"w"); // cria arquivo vazio
 return arquivo!=NULL; // informa se o arquivo foi aberto
} 

// Uma alternativa seria passar o parâmetro arquivo à função abrir() como um ponteiro de
// ponteiro, mas isso tornaria o código bem menos legível. 

// Parâmetros com valores default


void exibe(int num, int base=10); // base tem valor default igual a 10
void main(void)
{
 exibe(13); // decimal, por default
 exibe(13,2); // binário
 exibe(13,16); // hexadecimal
}
void exibe(int num, int base)
{
 char str[100];
 //itoa(num,str,base);
 cout << str << endl;
} 

// Parâmetros com valores default devem necessariamente ser os últimos da lista e podem
// ser declarados tanto no protótipo quanto no cabeçalho da função, desde que tal declaração apareça 
// antes de qualquer uso da função.

//A palavra-chave inline substitui vantajosamente a utilização da diretiva #define do
// preprocessador para definir pseudo-funções, ou seja, macros.
// Cada chamada de uma função inline é substituída por uma cópia do seu código, o que
// aumenta bastante a velocidade de execução do programa. Note porém que, por motivos
// de economia de memória, apenas funções muito curtas devem ser declaradas inline. A
// vantagem é que essas funções se comportam como funções normais e, portanto, permitem a consistência
// de tipo de seus parâmetros, o que não é possível com #define. 

inline double sqr(double n) { return n * n; }
void main(void)
{
 cout << sqr(10) << endl;
}

// Ao contrário das funções normais, as funções inline somente são visíveis dentro do
// arquivo no qual são definidas.

/*
O compilador selecionará a função a ser chamada tomando como base o número e o tipo dos parâmetros
reais especificados na sua chamada. Como essa escolha é feita em tempo de compilação, as funções 
sobrecarregadas têm desempenho idêntico às funções clássicas. Dizemos que as chamadas de funções 
sobrecarregadas são resolvidas de maneira estática. 
*/

int soma(int a, int b)
{
 return a+b;
}
int soma(int a, int b, int c)
{
 return a+b+c;
}
double soma(double a, double b)
{
 return a+b;
}
void main(void)
{
 cout << soma(1,2) << endl;
 cout << soma(3,4,5) << endl;
 cout << soma(6.7,8.9) << endl;
}