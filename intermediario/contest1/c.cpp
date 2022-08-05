
#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define FOR(a, n) for (int(a) = 0; (a) < (n); ++(a))

int main(){
    int n;
	string str_decoded, str_original;
	cin >> n >> str_original;
	int i = 0;
	while (n) {
		if ((n % 2) & 1) {
			str_decoded += str_original[i];
		} else {
			str_decoded = str_original[i] + str_decoded;
		}
		n -= 1;
		i += 1;
	}
	cout << str_decoded << '\n';

    return 0;
}