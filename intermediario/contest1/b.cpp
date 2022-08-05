
#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define FOR(a, n) for (int(a) = 0; (a) < (n); ++(a))

int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int res = 0;
        int diff = abs(b - a);
        
        if(diff >= 5){
            res += diff / 5;
            diff = diff - ((diff / 5) * 5);
        }
        if(diff >= 2){
            res += diff / 2;
            diff = diff - ((diff / 2) * 2);
        }
        if(diff >= 1){
            res += 1;
        }

        cout << res << endl;
    }
}