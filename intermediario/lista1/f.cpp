#include <bits/stdc++.h>
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define space " "
#define F first 
#define S second 
#define REP(i, a, b) for (int i=a; i<=b; i++)
#define FOR(a, n) for (int(a) = 0; (a) < (n); ++(a))
 
int main(){ sws;   
 
    int n;
    cin >> n;
    int v[n];

    FOR(i, n){
        cin >> v[i];
    }

    if(v[0] % 2 == 0){
        cout << "No" << endln;
        return 0;
    }

    if(n % 2 == 1 and v[0] % 2 == 1 and v[n-1] % 2 == 1){
        cout << "Yes" << endln;
        return 0;
    }

    int soma = 0, subconjunto = 0;
    FOR(i, n){
        if (i + 1 == n and v[i] % 2 == 0){
            cout << "No" << endln;
        }
        soma++;
        if (soma == 3) {
            soma = 0;
            subconjunto++;
        }
    }
    if (soma != 0) subconjunto++;
    if ((soma % 2 == 0 and soma != 0) or subconjunto % 2 == 0){
        cout << "No" << endln;
    }else{
        cout << "Yes" << endln;
    }
    return 0;
}