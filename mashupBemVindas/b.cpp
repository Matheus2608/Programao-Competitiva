#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
 
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int main(){
    sws;
    int n;
    char a, g;
    int corretas= 0;
    cin >> n;
    int nInicial = n;
    while(n--){
        cin >> a >> g;
        if(a == g){
            corretas++;
        }
    }
    // cout << corretas << " " << nInicial; 
    float resposta = (float) corretas / nInicial * 10;
    printf("Nota: %.2f", resposta);
    return 0;
}