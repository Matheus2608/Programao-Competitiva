#include <bits/stdc++.h> // Include every standard library
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int alvo1 =  n - 1;
    int alvo2 = n;
    
    if(v[alvo1] != v[alvo2]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}