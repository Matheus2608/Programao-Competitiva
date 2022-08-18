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
    int n, q, t; cin >> n >> q >> t;
    vector<ll> a(n+1, 0);
 
    vector<ll> psum(n+30), delta(n+30), delta2(n+30);
    ll l, r, x;
 
    while(q--){
        cin >> l >> r >> x;
        delta[l]+=x;
        delta[r+1]-=x;
    }
    
    ll soma = 0;
    int res = 0;
    for(int i = 1 ;i< n+1;++i){
        soma += delta[i]; 
        if(soma >= t) res++;
    }
    
    cout << res << endl;
    return 0;
}