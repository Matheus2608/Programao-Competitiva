#include <bits/stdc++.h>
using namespace std;
 
void solve() {
 
    int n;
    cin >> n;
 
    vector<int> arr(n);
 
    for(auto &x: arr)
        cin >> x;
    
    vector<int> ans(n, -2);
    stack<int> s;
 
    for(int i = n - 1; i >= 0; i--) {
 
        while(s.size() && arr[s.top()] <= arr[i])
            s.pop();
        
        if(s.size())
            ans[i] = s.top();
        
        s.push(i);
 
    }
 
 
    for(auto &x: ans)
        cout << x + 1 << " ";
    cout << "\n";
 
}
 
int main() {
 
    int t = 1;
 
    //cin >> t;
 
    while(t--) {
        solve();
    }
 
    return 0;
 
}