// O exemplo a seguir mostra a declaração de uma classe que representa datas compactadas em 16 bits, 
// segundo o esquema adotado pelo sistema DOS/Windows. Nesse esquema, o ano (menos 1980) é armazenado nos
// primeiros 7 bits da esquerda, o mês ocupa
// os próximos 4 bits e o dia ocupa o espaço restante. Note que a classe Data é definida
// como uma struct cujos membros são dados e funções. 
#include <bits/stdc++.h>
using namespace std;
struct Data {
 unsigned short data; // |7|4|5|
 void define(short d, short m, short a);
 void exibe(void);
};

void main(void)
{
 Data hoje;
 hoje.define(5,1,2000);
 hoje.exibe();
}

/*
• private: os membros privados somente são acessíveis às funções membros da classe.
A parte privada é também denominada implementação.
• protected: os membros protegidos são como os membros privados, mas eles são
também acessíveis às funções membros de classes derivadas.
• public: os membros públicos são acessíveis a todos. A parte pública é também
denominada interface. 
*/

// Por default, todos os membros de uma struct são públicos. Assim, se quisermos evitar o
// acesso indevido ao atributo data, da classe definida no exemplo 3.1, podemos alterar
// sua declaração conforme a seguir: 

struct Data {
 void define(short d, short m, short a);
 void exibe(void);
 private:
 unsigned short data;
}; 

// A diferença é que numa classe definida com essa nova palavra, o
// acesso aos campos é privado por default, ao contrário do que ocorre com as estruturas. 

class Data {
 unsigned short data;
 public:
 void define(short d, short m, short a);
 void exibe(void);
};

// O uso da palavra class tem como vantagem a garantia de que nenhum campo é deixado
// público por descuido. Entretanto, pode incentivar um estilo de codificação em que
// detalhes da implementação da classe aparecem antes da declaração de sua interface.
// Isso deve ser evitado, pois leva o usuário da classe a ter conhecimento de detalhes que 
// não são relevantes para quem a utiliza. É preferível listar primeiro os membros
// públicos e deixar os membros privados para depois.

class Data {
 public:
 void define(short d, short m, short a);
 void exibe(void);
 private:
 unsigned short data;
}; 

/*
Para associar a definição de função membro à sua respectiva
classe, devemos usar o operador de resolução de escopo (::). Dentro de uma função
membro, temos acesso direto a todos os outros membros da classe. 
*/

void Data::define(short d, short m, short a)
{
 data = ((a-1980)<<9) | (m<<5) | d;
}
void Data::exibe(void)
{
//  cout << setw(2) << setfill('0')
//  << (data & 0x1F) << "/"
//  << setw(2) << setfill('0')
//  << ((data>>5) & 0xF) << "/"
//  << (data>>9)+1980 << endl;
} 

// A definição de uma função membro também pode ser feita diretamente dentro da
// declaração da classe. Nesse caso, uma tal função é automaticamente tratada pelo
// compilador como sendo inline. Uma função membro definida em separado também
// pode ser qualificada explicitamente como sendo inline. 

class Data {
 public:
 void define(short d, short m, short a)
 {
 data = ((a-1980)<<9) | (m<<5) | d;
 }
 void exibe(void);
 private:
 unsigned short data;
}; 

// Lembre-se de que a visibilidade de uma função inline é restrita apenas ao módulo no
// qual ela é declarada, isso vale mesmo no caso de funções membros. 

Data hoje; // uma instância simples (estática)
Data *ontem; // um ponteiro, não inicializado
Data *amanha = new Data; // criação dinâmica de uma instância
Data cronograma[31]; // um vetor de instâncias

// Depois de criar um objeto, seja de maneira estática ou dinâmica, podemos acessar seus
// atributos e métodos. Esse acesso é feito como nas estruturas, através dos operadores
// ponto (.) ou seta (->). 

// hoje.define(5,1,2000); // ponto para instâncias
// amanha->define(6,1,2000); // seta para ponteiros
// cronograma[0].define(15,4,2000); 

/*
Certos métodos de uma classe não devem modificar os dados da classe. Nesse caso, as
funções que implementam tais funções devem ser declaradas como constantes. Esse
tipo de declaração reforça o controle efetuado pelo compilador e permite uma programação mais segura,
sem nenhum custo adicional de execução.
*/

// void Data::exibe(void) const
// {
//  cout << setw(2) << setfill('0')
//  << (data & 0x1F) << "/"
//  << setw(2) << setfill('0')
//  << ((data>>5) & 0xF) << "/"
//  << (data>>9)+1980 << endl;
// } 

// Apenas funções membros const podem ser chamadas a partir de objetos constantes.
// Entretanto, é possível sobrecarregar dois métodos com a mesma assinatura, desde que
// apenas um deles seja constante. Isso permite que o compilador selecione corretamente
// o método não constante para objetos não constantes, em vez de simplesmente gerar um
// erro de compilação.

class Pilha {
 public:
 Pilha(int);
 ~Pilha(void);
 void insere(int);
 int remove(void);
 int topo(void);
 bool vazia(void);
 bool cheia(void);
 private:
 int max;
 int top;
 int *mem;
};
Pilha::Pilha(int n)
{
 max = n;
 top = -1;
 mem = new int[n];
}
Pilha::~Pilha(void)
{
 delete[] mem;
}
void Pilha::insere(int e)
{
 if( !cheia() )
 mem[++top] = e;
 else
 cout << "pilha cheia!" << endl;
}
int Pilha::remove(void)
{
 if( !vazia() ) 
 return mem[top--];
 else {
 cout << "pilha vazia!" << endl;
 return 0;
 }
}
int Pilha::topo(void)
{
 if( !vazia() )
 return mem[top];
 else {
 cout << "pilha vazia!" << endl;
 return 0;
 }
}
bool Pilha::vazia(void)
{
 return top==-1;
}
bool Pilha::cheia(void)
{
 return top==max-1;
} 

Pilha p; // chama o construtor default
Pilha q(10); // chama construtor com um parâmetro
Pilha r = Pilha(10); // idem à instrução anterior
Pilha s[10]; // chama construtor default 10 vezes
Pilha *t; // não chama nenhum construtor
Pilha *u = new Pilha; // chama o construtor default
Pilha *v = new Pilha(5); // chama construtor com um parâmetro
Pilha x[3] = {Pilha(3), Pilha(9), Pilha(7)}; // inicia os elementos de x 

// converte de decimal para binário
void main(void)
{
 Pilha p(32);
 unsigned n;
 cout << "Número positivo? ";
 cin >> n;
 do {
 p.insere(n%2);
 n /= 2;
 } while( n!=0 );
 cout << "Binário: ";
 while( !p.vazia() )
 cout << p.remove();
 cout << endl;
}


void exibeTopo(Pilha q)
{
 cout << "Topo da pilha: " << q.remove() << endl;
}
void main(void)
{
 Pilha p(5);
 p.insere(99);
 exibeTopo(p);
}
/*
Como o passagem é por valor, o parâmetro formal q é criado como cópia temporária do
parâmetro real p. O valor existente no topo da pilha é corretamente exibido mas, ao
final da execução, o destrutor é chamado para liberar o espaço ocupado por q e acaba
liberando também o espaço alocado para os dados membros de p. Isso acontece porque
o objeto q contém ponteiros com os mesmos valores daqueles no objeto p.
Uma maneira imediata de resolver esse problema seria usar passagem por referência,
o que impediria a chamada do destrutor ao término da execução da função; mas isso
também causaria efeitos colaterais no valor do parâmetro real p, já que a função
exibeTopo() remove um elemento da pilha q.
Uma solução efetiva requer, portanto, a criação de um construtor de cópias. Esse construtor é invocado quando criamos um objeto a partir de um outro objeto existente da
mesma classe. O construtor de cópia é chamado também na passagem de argumentos
por valor e no retorno de objetos. 
*/

Pilha p(10); // chama o construtor com um parâmetro
Pilha q(p); // chama o construtor de cópia
Pilha r=p; // idem ao caso anterior