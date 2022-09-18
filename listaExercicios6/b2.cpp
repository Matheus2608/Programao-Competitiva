#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

int main(){ sws;   
    
    long long x; cin >> x;

    long long res = (-1 + pow((1 + 8 * x), 0.5)) / 2;
    cout << res + 1<< endl;
    return 0;
}
