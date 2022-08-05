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
 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))


#define B 32
bool isSet(int bitPosition, int number) {
  bool ret = ((number & (1 << bitPosition)) != 0);
  return ret;
}

int main(){ sws;   
    int a, b; cin >> a >> b;
    bitset<B> res;

    FOR(i,0,32){
        if(isSet(i,b)){
            if(isSet(i,a)) res[i] = 0;
            else res[i] = 1;
        }else{
            if(isSet(i,a)) res[i] = 1;
            else res[i] = 0;
        }
    }

    cout << res.to_ulong() << endln;
    return 0;
}
