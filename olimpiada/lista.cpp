#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n)

int main(){
    int n; cin >> n;
    int x[n];
    REP(i,n) cin >> x[i];

    int l = 0, r = n -1, res = 0;
    while(l<r){
        if(x[l] != x[r]) res++;
        l++;
        r--;
    }
    cout << res << endl;
    return 0;
}