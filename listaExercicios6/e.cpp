#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define endln "\n"
#define umap unordered_map
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

string s;
map<char, vi> m;

bool check(int k){
    for(auto elem : m){
        vi tmp = elem.second;
        bool achou = true;
        int l = 1, r = k;
        while(r <= s.size()){
            int alvo = *lower_bound(begin(tmp), end(tmp), l);
            if(alvo <= r){
                r++;
                l++;
                continue;
            }

            achou = false;
            break;
        }

        if(achou) return true;
    }

    return false;
}

int main(){sws;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        m[s[i]].push_back(i + 1);
    }

    
    int l = 1, r = s.size(), mid, res;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid)){
            res = mid;
            r = mid - 1;
        }

        else {
            l = mid + 1;
        }
    }

    cout << res << endl;
    return 0;

}