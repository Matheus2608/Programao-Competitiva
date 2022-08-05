#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"

int main(){
    sws;
    int m, n, res;
    cin >> m >> n;
    if (n % 2 == 0){
        res = n / 2 * m;
    }else{
        res = (n / 2 * m) + m / 2;
    }

    cout << res << endln;
    return 0;
    
}