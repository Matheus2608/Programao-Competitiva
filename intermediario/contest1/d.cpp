
#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define FOR(a, n) for (int(a) = 0; (a) < (n); ++(a))

int main(){
    int n, tmp;
    cin >> n;
    int arr[n] = {0};
    int min = 1000000005;
    FOR(i, n){
        cin >> tmp;
        arr[i] = tmp;
        if (arr[i] < min) min = tmp;
    }

    FOR(i,n) {
        if(arr[i] % min != 0){
            cout << -1;
            return 0;
        }
    }

    cout << min;
    return 0;
}