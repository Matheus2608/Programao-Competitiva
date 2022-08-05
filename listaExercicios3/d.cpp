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
    int n, m, comando; cin >> n;
    set<int> s;

    while(n--){
        cin >> comando >> m;
        if(comando == 1) s.insert(m);
        else{
            if(s.count(m)) cout << "Sim" << endl;
            else cout << "Nao" << endl;
        } 
    }
    
    return 0;
}
