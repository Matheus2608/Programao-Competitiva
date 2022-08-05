#include <bits/stdc++.h> // Include every standard library
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define B 32
 
bool isSet(int bitPosition, int number) {
  bool ret = ((number & (1 << bitPosition)) != 0);
  return ret;
}
 
int main(){ sws;   
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        //cout << bitset<B>(n) << endln;
        int res = n - 1;
        while(true){
            n = n & res;
            if(n == 0) break;
            res = n - 1;
        }
        cout << res << endln;
    }
    return 0;
}