#include <bits/stdc++.h> // Include every standard library
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

// int complement(string s){
//     int inicio = 0;
//     for(int i = 0; i < s.size(); i++){
//         if (s[i] == '1'){
//             inicio = i;
//             break;
//         }
//     }

//     string res = "";
//     for(int i = inicio; i < s.size(); i++){
//         s[i] == '1' ? res += '0' : res+= '1';
//     }

//     return stoi(res, 0, 2);
// }

int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int anD = (a&b);
        int res = (a^anD) + (b^anD);
        cout << res << endl;
    }
    return 0;
}