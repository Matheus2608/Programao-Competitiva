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
    int n, m; cin >> n >> m;
    vector<ll> v(n+1, 0);
    for(int i = 1 ;i< n+1;++i){
        cin >> v[i];
    }
 
    vector<ll> psum(n+30), delta(n+30), psumop(n+30), deltaop(n+30);
    ll l, r, x;
 
    while(m--){
        cin >> l >> r >> x;
        delta[l]-=x;
        delta[r+1]+=x;
        deltaop[l]++;
        deltaop[r+1]--;
    }
    
    ll soma = 0;
    for(int i = 1 ;i< n+1;++i){
        soma += delta[i];
        psum[i] = v[i] + soma;
    }

    soma = 0;
    for(int i = 1 ;i< n+1;++i){
        soma += deltaop[i];
        psumop[i] = soma;
    }

    int res = 0;
    for(int i = 1 ;i< n+1;++i){
        if(psum[i] > 0) res+=psumop[i];
    }

    cout << res << endl;
    return 0;
}