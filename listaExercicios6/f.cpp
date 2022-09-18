#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define endln "\n"
#define umap unordered_map
#define ll long long
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))


int main(){sws;
    int n, dindin; cin >> n >> dindin;
    int arr[n];
    for(int &i: arr) cin >> i;

    pair<int,int> res = {0,0};

    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        ll tmp[n];
        ll din = dindin;
        bool cond = true;
        for(int i = 0; i < n; i++){
            tmp[i] = arr[i] + mid * (i + 1);
        }

        sort(tmp, tmp + n);
        for(int i = 0; i < mid; i++){
            din -= tmp[i];
            if(din < 0) {cond = false; break;}
        }

        if(cond) {res.first = max(res.first, mid); res.second = dindin - din; l = mid + 1;}

        else r = mid - 1;
    }

    cout << res.first << " " << res.second << endl;
    return 0;

}