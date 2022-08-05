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
    //bitset<B>bitNot(notN);

    cout << bitN << endl;

    int ultimobitAtivo;
    for(int i = 63; i >= 0; i--){
        if(bitN[i] == 1) {ultimobitAtivo = i; break;}
    }

    ll x = 0;
    FOR(i,0,ultimobitAtivo){
            if(bitN[i] == 0)
                x += pow(2,i);
    }

    // cout << ultimobitInativo << endln;
    // cout << x << endln;
    cout << bitset<B>(x) << endln;
    cout << bitset<B>(n ^ x) << endln;
    cout << n << " " << x << endln;
    return 0;
}