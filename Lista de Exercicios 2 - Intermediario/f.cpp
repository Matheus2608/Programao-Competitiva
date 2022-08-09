
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
    queue<int> ras;
    string s; cin >> s;
    int res = 0;
    int tmp = 0;
    for(char c: s){
        if(!ras.empty() and c == '.'){
            tmp = ras.front(); tmp++; ras.pop();
            ras.push(tmp);
        }

        else if(c == 'r' and ras.empty()){
            ras.push(0);
        }

        else if(c == 'r' and !ras.empty()){
            res += ras.front();ras.pop();
            ras.push(0);
        }

        else if(c == 's' and !ras.empty()){
            ras.pop();
        }
    }
    if(!ras.empty()) res += ras.front();
    cout << res << endl;
    return 0;
}
