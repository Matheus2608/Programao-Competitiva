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
    int n, w;
    string s;

    cin >> n;
    priority_queue < pii , vector < pii > , greater<pii> > pq_pii;
    stack < int > pilha;
    for(int i = 1; i <= n; i++){
        cin >> w;
        pq_pii.push(mp(w, i));
    }

    cin >> s;
    for(char c : s){
        if(c == '0'){
            pii tmp = pq_pii.top();
            pq_pii.pop();
            cout << tmp.second << " ";
            pilha.push(tmp.second);
        }
        else{
            cout << pilha.top() << " ";
            pilha.pop();
        }
    }

    return 0;
}