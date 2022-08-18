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
	int t,pao,carne,frango,h,c,valor;
    cin>>t;
    while(t--){
        cin>>pao>>carne>>frango>>h>>c;
        int MAX = -1;
        queue<tuple<int,int,int,int>> fila;
        fila.push(make_tuple(0,pao,carne,frango));
        while(!fila.empty()){
            tie(valor,pao,carne,frango) = fila.front();fila.pop();
            MAX = max(valor,MAX);

            if(h > c){
                if(carne and pao >= 2)fila.push(make_tuple(valor+h,pao-2,carne-1,frango));
                else if(frango and pao >= 2)fila.push(make_tuple(valor+c,pao-2,carne,frango-1));
            }
            else{
                if(frango and pao >= 2)fila.push(make_tuple(valor+c,pao-2,carne,frango-1));
                else if(carne and pao >= 2)fila.push(make_tuple(valor+h,pao-2,carne-1,frango));
            }
        }
        cout << MAX << endln;
    }

    return 0;
}
