#include<bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define endln "\n"

int main()
{ sws;
  int t, n, elemento;
  cin >> t;
  while (t > 0){
    cin >> n;
    int array[n];
    for (int i=0; i<n; i++){
      cin >> elemento;
      array[i] = elemento;
    }
    
    int min = array[0], max = array[0];
    for (int i=0; i<n; i++){
      if (array[i] > max ) {
        max = array[i];
      }

      if (array[i] < min){
        min = array[i];
      }
    }

    cout << max - min << endln;
    t--; 
  }
  return 0;
}
