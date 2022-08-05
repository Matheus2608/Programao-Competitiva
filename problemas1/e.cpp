#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define space " "

int main(){ sws;   

    /* Insira o codigo-fonte aqui */
    int n;
    cin >> n;
    ll linha, coluna, celula;
    ll byrow[2];

    for (int i=0; i<n;i++){
        cin >> linha >>  coluna >> celula;
        byrow[1] = celula / linha;
        if (byrow[1] * linha == celula){
            byrow[0] = linha - 1;
            cout << coluna * byrow[0] + byrow[1] << endln;
        }else{
            byrow[0] = celula - byrow[1] * linha - 1;
            cout << coluna * byrow[0] + byrow[1] + 1 << endln;
        }
        //cout << byrow[0] << space << byrow[1] << endln;
    }
    return 0;
}