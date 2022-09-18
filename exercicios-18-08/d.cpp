#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define umap unordered_map
#define uset unordered_set
 
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)


int m;
vi res = {}, candidatos = {};

void dfs(vi& esquerda, vi& direita, int somaEsq, int somaDir, char vez){
    if((int) esquerda.size() + (int) direita.size() == m){
        REP(i, direita.size()){
            res.pb(esquerda[i]); res.pb(direita[i]);
        }
        if(esquerda.size() > direita.size()) res.pb(esquerda.back());
        return;
    }

    if(vez == 'e'){
        int numMinimo = somaDir - somaEsq;
        auto candidatoMin = upper_bound(ALL(candidatos), numMinimo);
        for(; candidatoMin != candidatos.end(); candidatoMin++){
            if((int) res.size()) break;
            if(somaDir != 0 and *candidatoMin == direita.back()) continue;
            
            //escolho
            esquerda.pb(*candidatoMin);
            dfs(esquerda, direita, somaEsq + (*candidatoMin), somaDir, 'd');
        }
    }

    else{
        int numMinimo = somaEsq - somaDir;
        auto candidatoMin = upper_bound(ALL(candidatos), numMinimo);
        for(; candidatoMin != candidatos.end(); candidatoMin++){
            if((int) res.size()) break;
            if(somaEsq != 0 and *candidatoMin == esquerda.back()) continue;
            
            //escolho
            direita.pb(*candidatoMin);
            dfs(esquerda, direita, somaEsq , somaDir + (*candidatoMin), 'e');

            
        }
    }
    
    return;
}

int main(){ sws;   
    string s; cin >> s;
    cin >> m;
    
    FOR(i,1,(int) s.size() + 1){
        if(s[i-1] == '1') candidatos.pb(i);
    }

    vi esquerda, direita;
    dfs(esquerda, direita, 0, 0, 'e');

    if(res.size()){
        cout << "YES" << endl;
        for(int& x: res){
            cout << x << " ";
        }
        cout << endl;
    }

    else cout << "NO" << endl;
    
    return 0;
}

/*
//nao escolho
            direita.pop_back();
            if(direita.size()) dfs(esquerda, direita, somaEsq , somaDir, 'e');
*/