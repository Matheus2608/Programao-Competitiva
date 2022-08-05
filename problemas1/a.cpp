#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

int main(){ sws;   

    /* Insira o codigo-fonte aqui */
    int limak, bob;
    int years = 0;
    cin >> limak >> bob;
    while (not(limak > bob)){
        limak *= 3;
        bob *= 2;
        years++;
    }
    cout << years << endln;
    return 0;
}