#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define endln "\n"
#define umap unordered_map

 
 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))


int main(){
    int n, dindin; cin >> n >> dindin;
    vi v(n);
    umap<int, int> mapa;
    int diff = 1e6;
    pair<int,int> res;
    FOR(i,0,n){
        cin >> v[i];
        if(mapa.count(v[i])) {
            int diff2 = abs(v[mapa[v[i]]] - v[i]);
            if(diff2 < diff){
                diff = diff2;
                res.first = v[mapa[v[i]]];
                res.second = v[i];
            }
        }
        mapa[dindin - v[i]] = i;
    } 

    if(res.first < res.second) cout << res.first << " " << res.second << endl;
    else cout << res.second << " " << res.first << endl;
    
    return 0;
}