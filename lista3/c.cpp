#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"

int main(){
    sws;
    int n, coin, soma = 0;
    
    cin >> n;
    int coins[n];

    for (int i = 0; i < n; i++){
        cin >> coin;
        soma += coin;
        coins[i] = coin;
    }


    sort(coins, coins+n, greater<int>());
    int somaTwin1 = 0, i = 0;
    while (somaTwin1 <= soma){
        somaTwin1 += coins[i];
        soma -= coins[i];
        i++;
    }

    cout << i << endln;
    
    return 0;
}