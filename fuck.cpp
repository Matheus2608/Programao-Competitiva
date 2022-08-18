#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        vector<float> delta(s+1, 1);
        vector<int> pmun(s, 1);
        for(int i = 0; i < s; i++){
            if(nums[i] == 0) {
                int a = s;
                for(int j = 0; j < s; j++){
                    if(j != i) delta[j] = 0;
                }
            }
            delta[0] *= nums[i];
            delta[i] = (float) delta[i] / nums[i];
            delta[i+1] *= nums[i];
        }
        
        int atual = 1;
        for(int i = 0; i < s; i++){
            atual *= delta[i];
            pmun[i] = atual;
        }
        
        return pmun;
    }


int main(){
    vector<int> x = {-1,-1,0,-3,3};
    productExceptSelf(x);
}