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
    vi a(n+1);
    for(int i = 1; i < n+1; i++){
        cin >> a[i];
    }
    int l, r;
    vector<ll> psum(n+1);
    
    for(int i = 1; i < n+1; i++){
        psum[i] = a[i] ^ psum[i-1];
    }
    while(q--){
        cin >> l >> r;
        cout << (psum[r] ^ psum[l-1]) << endln;
    }
    return 0;
}