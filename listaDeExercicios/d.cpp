#include <bits/stdc++.h> 
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define FOR(a, n) for (int(a) = 0; (a) < (n); ++(a))

int main(){
    sws;
    int n, tmp, res = 0, mx = -1;
    cin >> n;
    int arr[n];
    FOR(i, n){
        cin >> tmp;
        arr[i] = tmp;
        mx = max(mx, tmp);
    }


    FOR(i,n){
        res += (mx - arr[i]);
    }

    cout << res << endln;

    return 0;

}