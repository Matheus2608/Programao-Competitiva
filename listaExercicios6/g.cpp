#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define endln "\n"
#define umap unordered_map
#define ll long long
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

vi caixas;
bool condicao(int n, int maes){
    for(int caixa : caixas){
        if(maes <= 0) return true;
        while(caixa >= n){
            caixa -= n;
            maes--;
        }
    }

    return false;
}
int main(){sws;
    int n, m, tmp, maior = 0; cin >> n >> m;
    FOR(i,0,n){
        cin >> tmp;
        maior = max(maior, tmp);
        caixas.push_back(tmp);
    }

    if(m > (int) caixas.size()){
        maior = maior / (m - (int) caixas.size());
    }

    int l = 0, r = maior, res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(condicao(mid, m)){
            res = max(res, mid);
            l = mid + 1;
        }

        else r = mid - 1;

    }

    cout << res << endl;
    return 0;

}