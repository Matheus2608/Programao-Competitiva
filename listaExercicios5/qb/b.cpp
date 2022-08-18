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

int num_substring(string s){
	int t = s.size();
	int res = 0;
	FOR(i,0,t){
		if(s[i] == 'V' and i+1 < t and s[i+1] == 'K'){
			res++;
			i++;
		}
	}
	
	return res;
}
int main(){ sws;   
	string s; cin >> s;
	int x = num_substring(s);
	int tmp;
	for(char& c : s){
		if(c == 'V'){
			c = 'K';
			tmp = num_substring(s);
			if(tmp > x){
				cout << tmp; return 0;
			}else c = 'V';
		}
		
		if(c == 'K'){
			c = 'V';
			tmp = num_substring(s);
			if(tmp > x){
				cout << tmp; return 0;
			}else c = 'K';
		}
	}
	
	cout << x << endl;
    
    return 0;
}
