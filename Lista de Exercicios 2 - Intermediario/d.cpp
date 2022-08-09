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
    int n, luis, c, i; cin >> n >> luis >> c;

    priority_queue<tuple<int, int, int>, 
    vector<tuple<int, int, int>>, 
    greater<tuple<int, int, int>>> pqiii;
    int t, d, cBusao;
    vi freq(n+1);
    FOR(i,1,n+1){
        cin >> t >> d >> cBusao;
        if(cBusao <= c){
            pqiii.push(
                make_tuple(t, cBusao, i)
            );
            freq[i] = d;
        }
    }

    if(pqiii.empty()){
        cout << -1;
    }

    else{
        while(true){
            tie(t,cBusao, i) = pqiii.top(); pqiii.pop();
            if(t >= luis) {
                cout << i;break;
            }
            else{
                pqiii.push(
                    make_tuple(t+freq[i], cBusao, i)
                );
            }
        }
    }

    return 0;
}
