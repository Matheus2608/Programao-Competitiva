#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

int main(){
    sws;
    int n, erro; cin >> n;
    multiset<int> s, s2;

    FOR(i,0,n){
        cin >> erro;
        s.insert(erro);
    }

    s2 = s;

    FOR(i,0,n-1){
        cin >> erro;
        s.erase(s.find(erro));
    }

    FOR(i,0,n-2){
        cin >> erro;
        s2.erase(s2.find(erro));
    }

    for(auto erro: s) s2.erase(s2.find(erro));

    for(auto erro: s) cout << erro << endl;
    for(auto erro: s2) cout << erro << endl;   
    return 0;
}
