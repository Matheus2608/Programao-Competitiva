#include <bits/stdc++.h> 
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define FOR(a, n) for (int(a) = 0; (a) < (n); ++(a))

void soma(string &str, int atual){
    int res = str[atual] - '0' + 1;
    while(res == 0 or res == 10){
        str[atual] = '0';
        atual -= 1;
        res = str[atual] - '0' + 1;;
    }

    str[atual] = res + '0';
}

void recursao(string &str){
    for(int atual = (int) str.size() - 1; atual >= 0; atual--){
        for(int anterior = atual - 1; anterior >= 0; anterior--){
            if(str[atual] == str[anterior]){
                soma(str, atual);
                recursao(str);
            } 
        }
    }
}

int main(){
    sws;
    int x;
    cin >> x;
    
    while(true){ // maneira mais sequencial
        int contador = 0;
        x += 1;
        string str = to_string(x);
        int l = str.length();

        FOR(i,l){
            for(int j = i + 1; j < l; j++){
                if(!(str[i] != str[j])) contador++;
            }
        }

        if(contador == 0){
            cout << x << endln;
            break;
        } 

    } 
    
    return 0;

}

