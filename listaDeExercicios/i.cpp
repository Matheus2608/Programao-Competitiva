#include <bits/stdc++.h> 
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

int main(){
    sws;
    int n, x, y, preco;
    pii chico;
    
    cin >> n >> x >> y;
    int precos[n];
    pii localizacao[n];
    chico.first = x;
    chico.second = y;

    for(int i = 0; i < n; i++){
        cin >> x >> y >> preco;
        precos[i] = preco;
        pii tmp = mp(x, y);
        localizacao[i] = tmp;
    }

    for(int i = 0; i < n; i++){
        pii tmp = localizacao[i];
        int diff = abs(tmp.first - chico.first) + abs(tmp.second - chico.second);
        precos[i] += (diff * 2);
    }

    int precos2[n];
    for(int i = 0; i < n; i++){
        precos2[i] = precos[i];
    }

    sort(precos, precos + n);

    int menor = precos[0];
    int indice = 0;
    for(int i = 0; i < n; i++){
        if (precos2[i] == menor){
            indice = i + 1;
            break;
        }
    }
    cout << menor << " " << indice << endln;
    return 0;

}