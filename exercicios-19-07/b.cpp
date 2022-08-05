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
    int n, serval, t, f;
    cin >> n >> serval;
    vi freq(n+1);
    
    priority_queue < pii , vector < pii > , greater<pii> > pq_pii ;

    for(int i = 1; i <= n; i++){
        cin >> t >> f; 
        pq_pii.push(mp(t,i));
        freq[i] = f;
    }

    while(true){
        pii tmp = pq_pii.top();
        pq_pii.pop();
        if(tmp.first >= serval){
            cout << tmp.second << endl;
            break;
        }
        else{
            pq_pii.push(mp(tmp.first + freq[tmp.second], tmp.second));
        }
    }

    return 0;
}

