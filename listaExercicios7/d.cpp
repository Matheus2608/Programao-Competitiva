#include <bits/stdc++.h> // Include every standard library
using namespace std;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    
    map<char, set<int>> mapa;
    long long res = 0;
    int tamanhoSubString = 1;
    mapa[s[0]].insert(1);

    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]){
            tamanhoSubString++;
        }

        else{
            tamanhoSubString = 1;
        }

        mapa[s[i]].insert(tamanhoSubString);

    }

    for(auto elemento : mapa){
        res += elemento.second.size();
    }

    cout << res << endl;

    return 0;
}