#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

int main(){sws;

    ll n,m,k,l,r,d,x,y; cin >> n >> m >> k;


    vl delta(n+5), psum(n+5), vetor(n+5), soma(n+5);
    v<tuple(int,int,int)> operations(n+5)
    while(n--){
        cin >> vetor[n]
    }

    FOR(i,1,m+1){
        cin >> l >> r >> d;
        operations[i] = make_tuple(l,r,d);
    }
    
    while(q--){
        cin >> x >> y;
        delta[x]++;
        delta[y+1]--;
    }


    ll atual = 0;
    FOR(i,1,n+1){
        atual += delta[i];
        psum[i] = atual;
    }

    

    return 0;
}