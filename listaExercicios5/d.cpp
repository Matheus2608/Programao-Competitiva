#include <bits/stdc++.h> // Include every standard library
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
 
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
 
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
 
 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
 
bool busca_largura(int l, int r, int x, int y, int k){
    queue<pii> fila;
    int a,b;
    fila.push(mp(l,x));
    while(!fila.empty()){
        tie(a,b) = fila.front();fila.pop();
        if(b==0 and b+1>y) return false;
        int x = (int) a/b;
        if(x == k){
            return true;
        }
 
        if(x > k){
            if(a-1>=l){
                fila.push(mp(a-1,b));
                }
 
            if(b+1<=y){
                fila.push(mp(a,b+1));
            }
        }
 
        else if(a/b < k){
            if(a+1<=r){
                fila.push(mp(a+1,b));
            }
 
            if(b-1>=x){
                fila.push(mp(a,b-1));
            }
        }  
    }
 
    return false;
}
int main(){ sws;   
	int l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;
    if(busca_largura(l,r,x,y,k)) cout << "YES";
    else cout << "NO";
    
    return 0;
}