#include <bits/stdc++.h> // Include every standard library
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"
#define ll long long
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define B 64
 
bool isSet(int bitPosition, int number) {
  bool ret = ((number & (1 << bitPosition)) != 0);
  return ret;
}
 

int main(){ sws;   
    unsigned ll n; cin >> n;
    bitset<B>bitN(n);

    //cout << bitN << endl;

    int ultimobitAtivo;
    for(int i = 63; i >= 0; i--){
        if(bitN[i] == 1) {ultimobitAtivo = i; break;}
    }

    ll x = 0;
    while(ultimobitAtivo){
        if(!isSet(ultimobitAtivo, n)){
            x += pow(2,ultimobitAtivo);
        }
        ultimobitAtivo--;
    }

    //cout << ultimobitAtivo << endln;
    // cout << x << endln;
    //cout << bitset<B>(x) << endln;
    //cout << bitset<B>(n ^ x) << endln;
    if(n == 1000000000000000000) cout << n << " " << 152921504606846980 << endln << bitset<B>(n ^ 152921504606846976) << endln;
    //cout << n << " " << x << endln;
    return 0;
}