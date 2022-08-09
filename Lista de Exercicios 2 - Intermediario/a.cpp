#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

int main(){sws;
    int t, n, p; cin >> t;
    while(t--){
        deque<int> d;
        deque<int> res;
        cin >> n;
        vector<bool>removed(n+3);
        priority_queue<int> pq_max;
        for(int i = 0; i < n;i++){
            cin >> p;
            d.push_back(p);
            pq_max.push(p);
        }

        while(!pq_max.empty()){
            int Max = pq_max.top(); pq_max.pop();
            if(removed[Max]) continue;
            else{
                deque<int> prov;
                while(true){
                    int last = d.back(); d.pop_back();
                    removed[last] = true;
                    prov.push_front(last);
                    if(last == Max){
                        break;
                    }
                }

                while(!prov.empty()){
                    int tmp = prov.front(); prov.pop_front();
                    res.push_back(tmp);
                }
            }
        }
        while(!res.empty()){
            cout << res.front() << " "; ;res.pop_front();
        }

        cout << "\n";
    }
    return 0;
}