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


int main(){ sws;   
	string s1,s2;
    cin >> s1 >> s2;
    int pos1 = 0, pos2 = 0;

    for(char c: s1){
        if(c=='+') pos1++;
        else pos1--;
    }

    int naoReconhecido = 0;
    for(char c:s2){
        if(c=='+') pos2++;
        else if(c == '-')pos2--;
        else naoReconhecido++;
    }

    queue<pii> fila;
    fila.push(mp(pos2,0));
    int posAtual, numOp;
    int numPossibilidades = pow(2,naoReconhecido);
    while((int) fila.size() != numPossibilidades){
        tie(posAtual, numOp) = fila.front();
        if(numOp == naoReconhecido) continue;
        
        fila.pop();
        fila.push(mp(posAtual+1,numOp+1));
        fila.push(mp(posAtual-1,numOp+1));
    }

    float acertos = 0;
    while(!fila.empty()){
        int tmp = fila.front().first;fila.pop();
        //cout << tmp << " " << pos1 << endl;
        if(tmp == pos1) acertos++;
    }

    //cout << acertos;
    float res = acertos / (float) numPossibilidades;
    cout << fixed << setprecision(12);
    cout << res;
    return 0;
}
