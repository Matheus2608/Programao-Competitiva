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

int main(){sws;
    int n, first, num_q, q, cor; 
    cin >> n >> num_q;
    deque<int> cores;
    FOR(i,0,n){
        cin >> cor;
        cores.push_back(cor);
    }

    while(num_q--){
        cin >> q;
        bool achou = false;
        FOR(i,1,n+1){
            int tmp = cores.front(); cores.pop_front();
            if(!achou and tmp == q){
                cout << i << " ";
                first = tmp;
                achou = true;
                continue;
            }
        
            cores.push_back(tmp);
            
        }

        cores.push_front(first);
    }
    
    return 0;
}
