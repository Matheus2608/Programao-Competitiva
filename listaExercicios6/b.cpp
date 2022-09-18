#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))


unsigned long long somatorio(long long n){
    long long num = n * (n + 1);
    return num / 2;
}

int main(){ sws;   
    unsigned long long x; cin >> x;
    unsigned long long l = 0, r = 1e18, mid, soma, res = 1e18;
    while(l < r){
        mid = (l + r) / 2;
        soma = somatorio(mid);
        //cout << mid << " " << soma << endl;
        if(soma <= x) l = mid + 1;

        else if(soma > x){
            res = min(res, mid);
            r = mid - 1;
        }
    }

    cout << res << endl;
    
    return 0;
}
