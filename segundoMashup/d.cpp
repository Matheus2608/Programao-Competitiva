#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll n, tmp;
    cin >> n;
    ll arr[n];
    
    for (int i = 0; i < n; i++){
        cin >> tmp;
        arr[i] = tmp;
    }
    
    std::sort(arr, arr+n);
    ll soma1 = 0, soma2 = 0;
    for (int i = 0; i < n/2;i++){
        soma1 += arr[i];
    }
    
    for (int i = n - 1; i >= n/2;i--){
        soma2 += arr[i];
    }
    
    // if (n % 2 == 1){
    //     soma2 += arr[n/2];
    // }
    cout << (soma1 * soma1)  + (soma2 * soma2);
 
    return 0;
}