#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

int main(){
    sws;
    int n, u, capCaixa, v = 0; cin >> n >> u >> capCaixa;
    vi capMax(n), func(n);
    queue<pii> fila_caminhao;
    FOR(i,0,n){
        cin >> capMax[i];
    }

    FOR(i,0,n){
        cin >> func[i];
    }

    FOR(i,0,n){
        fila_caminhao.push(mp(capMax[i], func[i]));
    }
    pii caminhao_atual;
    int capAtual, funcAtual;
    while(!fila_caminhao.empty()){
        caminhao_atual = fila_caminhao.front(); fila_caminhao.pop();
        capAtual = caminhao_atual.first;
        funcAtual = caminhao_atual.second;
        if(funcAtual == 0){
            v += capAtual;
            u += v / capCaixa;
            v = v % capCaixa;
        }
        else{
            int numCaixas = capAtual / capCaixa;
            if(u == 0){
                fila_caminhao.push(caminhao_atual);
            }
            else{
                if(numCaixas > u) u = 0;
                else u -= numCaixas;
            }
        }
    }

    cout << ((capCaixa * u) + v) << endl;
    return 0;

}