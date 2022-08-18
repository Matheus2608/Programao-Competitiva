#include<bits/stdc++.h>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1);
    dp[0] = 1;
    for(int i = 1; i <= target; i++){
        for(int x : nums){
            if(x == i) dp[i] += 1;
            if(i-x>0) {
                dp[i] += dp[i-x];
            }
            else break;
        }
    }
    
    return dp[target];
}

int main(){
    vector<int> x = {1,2,3};
    int target = 4;
    cout << combinationSum4(x,target) << endl;
}