#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int lowerBoundFake(int target){
    int l = 0, r = v.size() - 1;
    int res = 1e9;
    while(l <= r){
        int mid = (l + r) / 2;
        if(v[mid] == target) return v[mid];

        if(v[mid] < target) l = mid + 1;
        else{
            res = min(res, v[mid]);
            r = mid - 1;
        }
    }

    if(res == 1e9) return -1; 
    return res;
}
int main(){
    int n, q, tmp, target; cin >> n >> q;
    
    while(n--) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(begin(v), end(v));

    while(q--){
        cin >> target;
        cout << lowerBoundFake(target) << endl;
    }

    return 0;
}