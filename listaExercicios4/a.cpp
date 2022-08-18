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
    int n, q; cin >> n >> q;
    vector<ll> a(n+1);
    for(int i = 0 ;i< n;++i){
        cin >> a[i];
    }

    vector<ll>  psum(n+1);
    psum[0] = a[0];
    for(int i = 1;i< n;++i){
        psum[i] = a[i] + psum[i-1];
    }
    int l, r;

    while(q--){
        cin >> l >> r;
        l--;
        r--;
        if(l==0) cout << psum[r] << endl;
        else cout << psum[r] - psum[l-1] << endl;
    }

    return 0;
}