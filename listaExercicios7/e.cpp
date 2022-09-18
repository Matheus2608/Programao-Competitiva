#include <bits/stdc++.h> // Include every standard library
using namespace std;

int main()
{
    int n, t; cin >> n >> t;

    vector<int> v(n);
    long long soma = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        soma += v[i];
    }

    int l = 0;
    int r = n - 1;
    
    while(l <= r){
        if(soma <= t){
            cout << r - l + 1 << endl;
            break;
        }

        else if(v[l] > v[r]){
            soma -= v[l];
            l++;
        }

        else{
            soma -= v[r];
            r--;
        }
    }

    return 0;
}