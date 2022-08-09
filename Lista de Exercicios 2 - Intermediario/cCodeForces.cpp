#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n);
  for (int& x : a) scanf("%d", &x);
  while (q--) {
    int x;
    scanf("%d", &x);
    int p = find(a.begin(), a.end(), x) - a.begin();
    printf("%d ", p + 1);
    rotate(a.begin(), a.begin() + p, a.begin() + p + 1);
  }
}