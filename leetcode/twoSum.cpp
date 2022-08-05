#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        int diff = target - nums[i];
        //cout << diff << endln;
        if (m.find(diff) != m.end()) {
            res.push_back(m[diff]);
            res.push_back(i);
            break;
            
        }
        else{
            m[nums[i]] = i;
        }
    }
    
    return res;
    }
};

int main() {
    sws;
    Solution s;
    vector<int> v = {2,7,11,15};
    auto x = s.twoSum(v, 9);
    for (auto i : x){
        cout << i << endl;
    }

}