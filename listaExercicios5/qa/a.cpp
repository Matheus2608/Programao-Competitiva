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
	int n, t; cin >> n >> t;
	vi a(n+1);
	for(int i = 1; i < n;i++){
		cin >> a[i];
	}
	queue<ll> pilha;
	pilha.push(1);
	ll tmp;
	while(!pilha.empty()){
		tmp = pilha.front();pilha.pop();
		if(tmp == t){
			cout << "YES" << endl; return 0;
		} 
		if(tmp < n)
			pilha.push(tmp+a[tmp]);
		else continue;
	}
	
	/*
	while(i < n){
		if(i == t) {}
		i+=a[i];
	}
    */
    
    cout << "NO" << endl;
    
    return 0;
}
