#include <bits/stdc++.h> // Include every standard library
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"
#define ll long long
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define B 64
 
 

int main(){ sws;   
    ll n; cin >> n;
    ll notN = ~n;

    bitset<B>bitN(n);
    bitset<B>bitnotN(notN);
    int ultimobitAtivo;
    for(int i = 63; i >= 0; i--){
        if(bitN[i] == 1) {ultimobitAtivo = i; break;}
    }

    for(int i = 63; i >= ultimobitAtivo; i--){
        bitnotN[i] = 0;
    }

    cout << n << " " << bitnotN.to_ulong() << endl;
    cout << bitset<B>(n ^ bitnotN.to_ulong()) << endl;
    return 0;
}