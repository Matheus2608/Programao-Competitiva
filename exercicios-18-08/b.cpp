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

char matriz[54][54];
bool visited[54][54];
bool achou = false;
int n, m;

void dfs(int i, int j, int x, int y, char cor){
    if(i < 0 or j < 0 or i >= n or j >= m) return;

    if(matriz[i][j] != cor) return;
    if(visited[i][j]){
        achou = true;
        return;
    }

    visited[i][j] = true;

    if(i+1 != x or j != y) dfs(i+1, j, i, j, cor);
    if(i != x or j + 1 != y) dfs(i, j + 1, i, j, cor);
    if(i-1 != x or j != y) dfs(i-1,j,i,j,cor);
    if(i != x or j-1 != y) dfs(i,j-1,i,j,cor);
}

int main(){ sws;   
    cin >> n >> m;
    REP(i, n){
        REP(j, m){
            cin >> matriz[i][j];
        }
    }

    REP(i, n){
        REP(j, m){
            if(!visited[i][j]){
                dfs(i,j,-1,-1,matriz[i][j]);
                if(achou){
                    cout << "Yes" << endl;
                    return 0;
                } 
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
