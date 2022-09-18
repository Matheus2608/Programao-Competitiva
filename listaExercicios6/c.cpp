#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int buscaBinariaRepetida(int target){
    int l = 0, r = v.size() - 1;

    while(l <= r){
        int mid = (l + r) / 2;
        if(v[mid] == target) {
            while(v[mid] == v[mid-1]) mid--;
            return mid + 1;
        }

        if(v[mid] < target) l = mid + 1;
        
        else
            r = mid - 1;
        
    }

    return -1; 
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
        cout << buscaBinariaRepetida(target) << " ";
    }

    cout << endl;
    return 0;
}