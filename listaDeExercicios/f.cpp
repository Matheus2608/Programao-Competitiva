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
    int n, a;
    cin >> n >> a;

    int resto = n % 500;
    resto <= a ? cout << "Sim" : cout << "Nao";
    return 0;

}