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

    vl delta(200005), psum(200005);
    ll n, k, q, l, r; cin >> n >> k >> q;
    
    while(n--){
        cin >> l >> r;
        delta[l]++;
        delta[r+1]--;
    }

    ll soma = 0;

    FOR(i,1,200005){
        soma += delta[i];
        if(soma >= k){
            psum[i] = psum[i - 1] + 1;
        }else{
            psum[i] = psum[i-1];
        }
    }

    while(q--){
        cin >> l >> r;
        cout << psum[r] - psum[l-1] << endl;
    }

    return 0;
}