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
    int n, tmp; cin >> n;
    bool zero = false;
    stack<int> vagaoSaida, vagaoEntrada;
    while(true){
        FOR(i,0,n){
            vagaoEntrada.push(i+1);
            cin >> tmp;
            if(tmp) vagaoSaida.push(tmp);
            else {
                cout << "\n";
                zero = true;
                break;
            }
        }

        if(!zero){
            
        }

        else {
            cin >> n;
            if(n == 0) break;
            else {
                continue;
                zero = false;
            }
        }   
    }


    return 0;
}