#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endln "\n"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        map<char,int> m;
        for (char c: s){
            if (m.count(c) == 0) m[c] = 1;
            else m[c] += 1;
        }

        for (char c : t){
            if (m[c] == 0  ) return false;
            m[c] -= 1;
        }

        return true;
        }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        vector<vector<string>> res;
        vector<string> x = {strs[0]};
        res.push_back(x);
        for (int i = 1; i < (int) strs.size(); i++){
            for (int j = 0; j < (int) res.size(); j++){
                if (isAnagram(strs[i], res[j][0])){
                    res[i].push_back(strs[i]);
                    break;
                }

                if (j == (int) res.size() - 1){
                    vector<string> tmp = {strs[i]};
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};

int main() {
    sws;
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto res = s.groupAnagrams(strs);
    for (auto vetor : res){
        for (string s : vetor){
            cout << s << " ";
        }
        cout << endln;
    }
    
    
}