#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int a[N];
 
int solve() {
    int n; cin >> n;
 
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    map<int, int> mx;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int steps = 0; // quantos passos o a[i] tem que dar pra virar ímpar
                       // note que steps = O(log a[i])
        for (; x % 2 == 0; x /= 2)
            steps++;
 
        mx[x] = max(mx[x], steps);
    }
 
    int ans = 0;
    for (auto [x, steps] : mx)
        ans += steps;
    return ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
 
    return 0;
}