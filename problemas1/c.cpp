#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

int main(){ sws;   

    /* Insira o codigo-fonte aqui */
    int n;
    cin >> n;
    int previous = 100000;
    int before, after;
    while (n > 0){
        //cout << n << endln;
        cin >> before >> after;
        if (before != after){
            cout << "rated" << endln;
            return 0;
        }
        if (before > previous){
            cout << "unrated" << endln;
            return 0;
        }
        previous = before;
        n--;
    }
    cout << "maybe" << endln;
    return 0;
}