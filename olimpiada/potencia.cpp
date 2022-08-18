#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n)

int main(){
    int n; cin >> n;
    int x[n];
    REP(i,n) cin >> x[i];
    long long soma = 0;
    for(int i : x){
        int last =  i % 10;
        i /= 10;
        soma += pow(i,last);
    }

    cout << soma << endl;
    return 0;
}