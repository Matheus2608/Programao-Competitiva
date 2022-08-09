#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

int n = 3;
bool chosen[3];
vi permutation;
void search() {
    if ((int) permutation.size() == n) {
        FOR(i,0,n){
            cout << permutation[i] << " ";
        }
        cout << endl;
    } 
    
    else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void search2(){
    vector<int> permutation2;
    int n = 3;
    for (int i = 0; i < n; i++) {
    permutation2.push_back(i);
    }
    do {
        FOR(i,0,n){
            cout << permutation2[i] << " ";
        }
        cout << endl;
    } while (next_permutation(permutation2.begin(),permutation2.end()));
    }

int main(){sws;
    search();
    search2();
    return 0;
}