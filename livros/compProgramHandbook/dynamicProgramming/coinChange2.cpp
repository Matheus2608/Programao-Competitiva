#include <bits/stdc++.h> // Include every standard library
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

int change(int amount, vector<int>& coins) {
    vector<vector<unsigned int>> dp( amount + 1, vector<unsigned int>( coins.size() + 1, 0 ) );
    for(unsigned int &x : dp[0]) x = 1;
    for(int a = 1; a <= amount; a++){
        for(int i = (int) coins.size() - 1; i >= 0 ; i--){
            dp[a][i] = dp[a][i+1];
            if(a - coins[i] >= 0){
                dp[a][i] += dp[a-coins[i]][i];
            } 
        }
    }
    
    return dp[amount][0];
}

int main(){
    sws;
    vi coins = {1,2,5};
    int amount = 5;
    cout << change(amount, coins) << endl;
    return 0;
}