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
    int n;
    cin >>n;
    string arr[n], arrfixo[n], tmp;
    FOR(i,n){
        cin >> tmp;
        arr[i] = tmp;
        arrfixo[i] = tmp;
    }

    sort(arr, arr+n);

    FOR(i,n){
        tmp = arrfixo[i];
        FOR(j,n){
            if(arr[j] == tmp){
                cout << j << " "; 
                break;
            } 
        }
    }
    return 0;

}