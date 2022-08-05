#include <bits/stdc++.h> 
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define FOR(a, n) for (int(a) = 1; (a) <= (n); ++(a))


void checa(int i){
    

}
int main(){
    sws;

    int n, a, b;
    cin >> n >> a >> b;
    int res = 0;
    for(int i = 0; i <=n; i++){
        int soma = 0;
        int tmp = i;
        while(tmp > 0){
            soma += tmp  % 10;
            tmp /= 10;
        }
        if (soma >= a and soma <= b) res+= i;
    }

    cout << res << endln;
    
    
    return 0;

}

