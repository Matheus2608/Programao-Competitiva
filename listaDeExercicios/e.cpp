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
    int n, res = 0;
    cin >> n;
    int arr[n];

    FOR(i, n) cin >> arr[i];
    sort(arr, arr+n);

    int last = 0;
    for(int i = 1; i <= n; i++){
        for(int j = last; j < n; j++){
            if(arr[j] >= i){
                last = j + 1;
                res++;
                break;
            }
        }
    }

    cout << res << endln;
    return 0;

}