#include<bits/stdc++.h>
using namespace std;

int main(){
    int x[4];
    for(int i = 0; i < 4;i++){
        cin >> x[i];
    }

    sort(x,x+4);
    int diff = abs((x[0] + x[3]) - (x[2] + x[1]));
    cout << diff << endl;
    return 0;
}