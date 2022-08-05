#include <bits/stdc++.h> // Include every standard library
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
    int n,t,c, gravidade, res = 0; cin >> n >> t >> c;
    queue < int > fila ;
    while(n--){
        cin >> gravidade;

        if(gravidade <= t) fila.push(gravidade);
        else{
            while(fila.size()){
                fila.pop();
            }
            continue;
        }
        if((int) fila.size() == c){
            res++;
            fila.pop();
        }
    }

    cout << res << endl;
    return 0;

}