#include <bits/stdc++.h> // Include every standard library
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
 
int main(){
    sws;
    int n, q, l, r; cin >> n >> q;
    ll tmp;

    priority_queue<ll> pq_max;
    priority_queue< pair<ll,ll> > pqii_max;
    vector<ll> delta(n+20), psum(n+20), res(n+20);
    vector<pair<ll,ll>> operacoes;

    for(int i = 1; i < n+1; i++){
        cin >> tmp;
        pq_max.push(tmp);
    }
    
    while(q--){
        cin >> l >> r;
        operacoes.pb( mp(l,r) );
        delta[l]++;
        delta[r+1]--;
    }
    
    tmp = 0;
    for(int i = 1; i < n+1; i++){
        tmp += delta[i];
        pqii_max.push( mp(tmp, i) );
    }

    for(int i = 1; i < n+1; i++){
        pair<ll,ll> x = pqii_max.top(); pqii_max.pop();
        ll Max = pq_max.top(); pq_max.pop();
        res[x.second] = Max;
    }

    ll soma = 0;
    for(int i = 1; i < n+1; i++){
        soma += res[i];
        psum[i] = soma;
    }

    soma = 0;
    for(pii x : operacoes){
        tie(l,r) = x;
        soma += psum[r] - psum[l-1];
    }
    
    cout << soma << endl;
    return 0;
}