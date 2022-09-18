
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
/*
    set<vector<int>> res;
    
    void backtrack(int i, vector<int>& candidatos, vector<int>& vAtual, int target){
        if(target == 0){
            res.insert(vAtual);
            return;
        }

        if(target < 0) return;

        if(i >= (int) candidatos.size()) return;

        //escolhi
        vAtual.push_back(candidatos[i]);
        backtrack(i + 1, candidatos, vAtual, target - candidatos[i]);
        vAtual.pop_back();

        //nao escolhi o numero
        backtrack(i + 1, candidatos, vAtual, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<int> vAtual;
        backtrack(0, candidates, vAtual, target);
        vector<vector<int>> res2;
        for(auto arr : res) res2.push_back(arr);
        return res2;
    }
*/

vector<vector<int>> combinationSum2(vector<int>& A, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(A.begin(), A.end());
    combinationSum2(A, 0, path, target, res);
    return res;
}

void combinationSum2(vector<int>& A, int pos, vector<int> &path, int target, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(path);
        return;
    }
    if (pos == A.size() || target - A[pos] < 0) return;
    auto num = A[pos++];
    path.push_back(num);
    combinationSum2(A, pos, path, target - num, res);
    path.pop_back();
    
    while (A[pos] == num) ++pos;
    combinationSum2(A, pos, path, target, res);
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }



int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    auto x = combinationSum2(candidates, target);
    for(auto arr : x){
        for(int e : arr){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}