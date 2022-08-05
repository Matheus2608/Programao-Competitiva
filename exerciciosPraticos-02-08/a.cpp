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

    vi delta(100001), psum(100001);
    int n, l, r;
    cin >> n;
    while(n--){
        cin >> l >> r;
        delta[l]++;
        delta[r+1]--;
    }

    FOR(i,1,100001){
        psum[i] = psum[i-1] + delta[i];
    }

    cout << *max_element(psum.begin(), psum.end());
    return 0;
}