
#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define FOR(a, n) for (int(a) = 0; (a) < (n); ++(a))

int main(){
    int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if (v[n - 1] < v[n - 2] + v[n - 3]) {
		cout << "YES" << '\n';
		for (int i = 0; i < n - 3; i++) {
			cout << v[i] << " ";
		}
		cout << v[n - 3] << " " << v[n - 1] << " " << v[n - 2];
	} else {
		cout << "NO" << '\n';
	}

    return 0;
}