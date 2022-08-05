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
    ll n; cin >> n;
    ll maxIntervalo = n;
    unsigned ll notN = ~n;
    cout << bitset<64>(n) << endln;

    int ultimoBitAtivo;
    for(int i = 64; i >= 0; i--){
        if(bitn[i]) {ultimoBitAtivo = i; break;}
    }
    
    while(true){
        for(int i = 31; i >= 0; i--){
            if(!isSet(i, notN)) {ultimobitInativo = i; break;}
        }
 
        ll x = 0;
        FOR(i,0,ultimobitInativo){
            if(isSet(i,notN))
                x += pow(2,i);
        }
 
        if(x >= 0 and x <= maxIntervalo and(n >= 0 and n <= maxIntervalo)){
            //cout << n << " " << x << endln;
            cout << bitset<64>(x)  << endln;
            //cout << (x < n) << endln;
            break;
        } 
        else n--;
        notN = ~n;
    }
    
    return 0;
}