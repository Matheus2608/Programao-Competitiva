#include <bits/stdc++.h>
using namespace std;
// cin -> input, cout -> output, cerr > erro

/*
Manipuladores
Os manipuladores são elementos que determinam o formato em que os dados serão
escritos ou lidos de um fluxo.
Os principais manipuladores são: 
oct     leitura e escrita de um inteiro octal
dec     leitura e escrita de um inteiro decimal
hex     leitura e escrita de um inteiro hexadecimal
endl    insere um caracter de mudança de linha
setw(int n)     define campo com largura de n caracteres
setprecision(int n)     define total de dígitos na impressão de números reais
setfill(char c)     define o caracter usado no preenchimento de campos
flush   descarrega o buffer após a escrita
*/

//#include <iostream.h>
//#include <iomanip.h>
void main(void)
{
 int i=1234;
 float p=12.3456F;
 cout << "|"
 << setw(8) << setfill('*')
 << hex << i
 << "|\n"
 << "|"
 << setw(6) << setprecision(4)
 << p
 << "|" << endl;
}

// Resultado da execução:
// |*****4d2|
// |*12.35| 


/*
O operador de resolução de escopo (::) nos permite acessar uma variável global, mesmo
que exista uma variável local com o mesmo nome. 
*/

int n=10;
void main(void)
{
 int n=20;
 {
 int n=30;
 ::n++; // altera variável global
 cout << ::n << "" "" << n << endl;
 }
 cout << ::n << " " << n << endl;
}


/*
Para definir constantes, em C++, usamos a palavra reservada const. Um objeto assim
especificado não poderá ser modificado durante toda a sua existência e, portanto, é
imprescindível inicializar uma constante no momento da sua declaração. 

*/
const float pi = 3.14;
const int meses = 12;
const char *msg = "pressione enter...";

/*

É possível usar a palavra const também na definição de ponteiros. Nesse caso, deve
estar bem claro o que será constante: o objeto que aponta ou aquele que é apontado.


*/
const char * ptr1 = "um"; // o objeto apontado é constante
char * const ptr2 = "dois"; // o objeto que aponta é constante
const char * const ptr3 = "três"; // ambos são constantes

/*
Assim como em C, em C++ podemos definir novos tipos de dados usando as palavras
reservadas struct, enum e union. Mas, ao contrário do que ocorre na linguagem C, a
utilização de typedef não é mais necessária para renomear o tipo.

*/
struct Ficha {
 char *nome;
 char *fone;
};
Ficha f, *pf;

/*
Em C++, cada enumeração enum é um tipo particular, diferente de int, e só pode armazenar
 aqueles valores enumerados na sua definição. 

*/
enum Logico { falso, verdade };
Logico ok;
//ok = falso;
//ok = 0; // erro em C++, ok não é do tipo int
//ok = Logico(0); // conversão explícita permitida

/*
Além de ponteiros, a linguagem C++ oferece também as variáveis de referência. Esse
novo recurso permite criar uma variável como sendo um sinônimo de uma outra.
Assim, modificando-se uma delas a outra será também, automaticamente, atualizada. 

*/
void main(void)
{
 int n=5;
 int &nr = n; // nr é uma referência a n
 int *ptr = &nr; // ptr aponta nr (e n também!)
 cout << "n = " << n << " nr = " << nr << endl;
 n += 2;
 cout << "n = " << n << " nr = " << nr << endl;
 *ptr = 3;
 cout << "n = " << n << " nr = " << nr << endl;
} 

/*
C++ oferece dois novos operadores, new e delete, em substituição respectivamente às
funções malloc() e free(), embora estas funções continuem disponíveis.
O operador new aloca um espaço de memória, inicializa-o e retorna seu endereço. Caso
a quantidade de memória solicitada não esteja disponível, o valor NULL é devolvido.

*/
int *p1 = new int; // aloca espaço para um int
int *p2 = new int(5); // aloca um int com valor inicial igual a 5
int *p3 = new int[5]; // aloca espaço para um vetor com 5 elementos
int (*p4)[3] = new int[2][3]; // aloca uma matriz de int 2x3 

//Cuidado para não confundir a notação:
int *p = new int(5); // aloca espaço para um int e armazena nele o valor 5
int *q = new int[5]; // aloca espaço para um vetor com 5 elementos do tipo int

// Para liberar espaço alocado a um vetor, devemos usar o operador
// delete[]. A aplicação do operador delete a um ponteiro nulo é legal e não causa qualquer
// tipo de erro; na verdade, a operação é simplesmente ignorada.

//delete p; // libera um objeto
//delete[] q; // libera um vetor de objetos 

// É preciso observar que:
// • a cada operação new deve corresponder uma operação delete;
// • é importante liberar memória assim que ela não seja mais necessária;
// • a memória alocada é liberada automaticamente no final da execução do programa. 