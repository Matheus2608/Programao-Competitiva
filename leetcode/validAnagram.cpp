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
};

int main() {
    sws;
    Solution s;
    cout << s.isAnagram("ab", "ab") << endln;
}