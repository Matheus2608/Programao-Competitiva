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
    int n, x, res; cin >> n;
    map <int, int > retirados;
    stack<int> pilha;
    priority_queue <int> pq_max ;

    char comando;
    while(n--){
        cin >> comando >> x;
        if(comando == 'A'){
            pq_max.push(x);
            pilha.push(x);
        }
        else if(comando == 'V'){
            if(pq_max.empty()) {
                cout << 0 << endl;
                continue;
            }
            res = pq_max.top();
            while(retirados[res]){
                pq_max.pop();
                retirados[res]--;
                res = pq_max.top();
            }

            if(pq_max.empty()) {
                cout << 0 << endl;
                continue;
            }
            cout << res << endl;
            
        }
        else{
            retirados[pilha.top()]++;
            pilha.pop();
        }
    }
    return 0;
}
