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
    string s; cin >> s;
    stack<char> pilha;
    for(char c : s){
        if(c == '(') pilha.push(c);
        else if(c == ')'){
            if(pilha.empty()){
                cout << "nao"; return 0;
            }
            else pilha.pop();
        }
    }
    if(pilha.empty()) cout << "sim";
    else cout << "nao";
    return 0;
}
