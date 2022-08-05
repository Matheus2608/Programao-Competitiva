#include <bits/stdc++.h> 
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
    
    int n, g, f, c;
    cin >> n >> g >> f >> c;
    int res = c;
    while(g && f){
        res++;
        g--;
        f--;
    }

    res > n ? cout << n << endln : cout << res << endln;
    return 0;
}

