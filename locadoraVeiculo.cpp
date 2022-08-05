#include <bits/stdc++.h> 
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Usuario{
    protected:
        string nome, telefone;
        int id;
    
    public:
    Usuario(){}
     Usuario(int id, string nome, string telefone){
        this->id = id;
        this->nome = nome;
        this->telefone = telefone;
    }
    
};

class Motorista : public Usuario{
    private:
     string CNH;
    
    public:
    Motorista(){}
     Motorista(int id, string nome, string telefone, string CNH) : Usuario(id, nome, telefone){
        this->CNH = CNH;
    }

    string getNome(){
        return this->nome;
    }
    
};


class Cliente : Usuario{
    private:
    string RG, CPF;
    
    public:
    Cliente(){}
    Cliente(int id, string nome, string telefone, string RG, string CPF): Usuario(id, nome, telefone){
        this->RG = RG;
        this->CPF = CPF;
    }
    
    string getRG(){
        return this->RG;
    }
};

class Veiculo{
    private:
    string placa, marca, modelo, cor;
    int ano;
    
    public:
     Veiculo(string placa, string marca, string modelo, string cor, int ano){
        this->placa = placa;
        this->marca = marca;
        this->modelo = modelo;
        this->cor = cor;
        this->ano = ano;
    }
    
    string getPlaca(){
        return this->placa;
    }
};

class Chamado
{
    private:
    Cliente cliente();
    Motorista motorista();
    Veiculo veiculo();
    
    int id;
    string data, tipo, origem, destino;
    float partida, retorno;
    double qInicial, qFinal, valorTotal; 
    
    public:
    
    Chamado(Cliente cliente(), Motorista motorista(), Veiculo veiculo(), int id, string data, string tipo, string origem, string destino, float partida, float retorno, double qInicial, double qFinal, double valorTotal){
        this->cliente() = cliente();
        this->motorista() = motorista();
        this->veiculo() = veiculo();
        
        this->id = id;
        this->data = data;
        this->tipo = tipo;
        this->origem = origem;
        this->destino = destino;
        this->partida = partida;
        this->retorno = retorno;
        this->qInicial = qInicial;
        this->qFinal = qFinal;
        this->valorTotal = valorTotal;
    }
    
    int getId(){
        return this->id;
    }
    
    string getDestino(){
        return this->destino;
    }

    Veiculo getVeiculo(){
        return this->veiculo();
    }

    Motorista getMotorista(){
        return this->motorista();
    }

    Cliente getCliente(){
        return this->cliente();
    }
    
};

int main(){
    sws;
    //  placa (string), marca (string), modelo (string), cor (string) e ano (int)
    string placa, marca, modelo, cor;
    int ano;
    
    
    cin >> placa >> marca >> modelo >> cor >> ano;
    Veiculo veiculo(placa, marca, modelo, cor, ano);
    
    //   id (int), nome (string), telefone (string), CNH (string).
    string nome, telefone;
    int id;
    
    string CNH;
    cin >> id >> nome >> telefone >> CNH;

            
    Motorista motorista(id, nome, telefone, CNH);
    
    //  id (int), nome (string), telefone (string), RG (string), CPF (string)
    string RG, CPF;
    cin >> id >> nome >> telefone >> RG >> CPF;
            
    Cliente cliente(id, nome, telefone, RG, CPF);
    
    //  id do chamado (int), a data (string), o tipo (string), a origem e o destino (string), os horários de partida e retorno (float), a quilometragem inicial e final do veículo (double), o valor total do chamado (double). 
    string data, tipo, origem, destino;
    float partida, retorno;
    double qInicial, qFinal, valorTotal;
    
    cin >> id >> data >> tipo >> origem >> destino >> partida >> retorno >> qInicial >> qFinal >> valorTotal;

    Chamado chamado(cliente, motorista, veiculo, id, data, tipo, origem, destino, partida, retorno,  qInicial, qFinal, valorTotal);
    cout << chamado.getId() << endl;
    cout << chamado.getDestino() << endl;
    cout << chamado.getVeiculo().getPlaca() << endl;
    cout << chamado.getCliente().getRG() << endl;
    cout << chamado.getMotorista().getNome() << endl;
    return 0;
}
