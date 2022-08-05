#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef double db;
// header \\
 
// g++ -o s -std=c++17 ./template.cpp && ./s.exe
 
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  ll n, m;
  cin >> n;
 
  int k = log2(n)+1;
  m = (ll) 1 << k;
  cout << bitset<7>(~n) << endl << bitset<7>(m) << endl << bitset<7>(~n + m) << endl << (~n + m); 
//   cout << n << " " << (~n + m) << endl;
}

/*
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  ll n; cin >> n;
  int msb = __builtin_clzll(n);
  cout << n << " " << (~n<<msb>>msb) << "\n";
}

int main()
{
    ll a, x, num;
    cin >> a;
    x = log2(a);
    num = (ll)1 << x;
    num = ((num | (num-1)) ^ a);
    cout << a << " " << num;
 
}

#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
  long long unsigned int n, x;
  cin >> n;
  x = n;
 
  int prefix = 63;
 
  while (x > 1) {
    prefix--;
    x >>= 1;
  }
 
 
  cout << n << " " << (~n << prefix >> prefix) << endl;
  return 0;
}
*/