#include <bits/stdc++.h> 
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

int main(){
    sws;
    int n, m, c;
    string s;
    cin >> n >> m;

    int primeiralinha1 = -1, ultimalinha1, primeiracoluna1, ultimacoluna1; 
    for(int i = 0; i < n; ++i){
        cin >> s;
        for(int j = 0; j < m; ++j){
            c = s[j] - '0';
            if (c){
                if(primeiralinha1 == -1){
                    primeiralinha1 = i;
                    ultimalinha1 = i;
                    primeiracoluna1 = j;
                    ultimacoluna1 = j;
                }

                ultimalinha1 = max(ultimalinha1, i);
                ultimacoluna1 = max(ultimacoluna1, j);
            }
        }
    }
    if(primeiralinha1 == -1) cout << "0x0" << endln;
    else cout << (ultimacoluna1 - primeiracoluna1 + 1) << "x" << (ultimalinha1 - primeiralinha1 + 1) << endln;
    return 0;

}