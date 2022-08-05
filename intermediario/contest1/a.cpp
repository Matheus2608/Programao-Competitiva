
#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define FOR(a, n) for (int(a) = 0; (a) < (n); ++(a))

int main(){
    int t, arr[10] = {0};
	string s;
	cin >> t >> s;
	int esq = 0, dir = 9;
	for (int i = 0; i < t; i++) {
		if (s[i] == 'L') {
			while (arr[esq]) esq++;
			arr[esq] = 1;
		} else if (s[i] == 'R') {
			while (arr[dir]) dir--;
			arr[dir] = 1;
		} else {
			int x = s[i] - '0';
			arr[x] = 0;
			esq = min(esq, x);
			dir = max(dir, x);
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i];
	}
	cout << '\n';
}