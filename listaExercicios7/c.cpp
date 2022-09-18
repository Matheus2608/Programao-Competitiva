#include <bits/stdc++.h> // Include every standard library
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> antes(n), depois(n);

    for(int i = 0; i < n; i++){
        cin >> antes[i];
    }

    for(int i = 0; i < n; i++){
        cin >> depois[i];
    }
    
    map<int, vector<int> > diferencas; // diferenca -> indice

    for(int i = 0; i < n; i++){
        diferencas[antes[i] - depois[i]].push_back(i);
    }

    long long res = 0;
    int pegosAgora = 0;
    for(auto diferenca : diferencas){
        for(int indice : diferenca.second){
            if(diferenca.first > 0 && pegosAgora >= k) res += depois[indice]; // vale a pena comprar depois
            else{
                res += antes[indice];
                pegosAgora++;
            }
        } 
    }

    cout << res << endl;

    return 0;
}