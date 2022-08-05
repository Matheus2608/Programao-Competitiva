#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"

int main(){
    sws;
    int q, n, good, initialN;

    cin >> q;
    while(q--){
        cin >> n;
        int soma = 0;
        initialN = n;
        while(n--){
            cin >> good;
            soma += good;
        }
        //cout << "soma = " << soma << " n = " << initialN << " divisao = " << (soma / initialN) << endln;
        if(soma % initialN > 0) cout << (soma / initialN) + 1 << endln;
        else cout << soma / initialN << endln;
    }
    
    return 0;
}