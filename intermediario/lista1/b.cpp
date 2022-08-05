#include <bits/stdc++.h>
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define space " "
 
int main(){ sws;   
 
    /* Insira o codigo-fonte aqui */
    string input;
    int change = 0;
    cin >> input;
    int inicio = 0;
    int final = input.size() - 1;
    
    while (inicio < final){
        //cout << input[inicio] << " " << input[final] << endln;
        if(input[inicio] != input[final]){
            change++;
        }
        inicio++;
        final--;
        //cout << "inicio: " << inicio << ",final: " << final << ",change: " << change << endln;
    }
    if (input.size() % 2 == 0){
        if (change == 1){
            cout << "YES" << endln;
        }else{
            cout << "NO" << endln;
        }
    }else{
        // pode mudar o caractere do meio sempre, por isso pode ser 0
        if (change <= 1){
        cout << "YES" << endln;
        }else{
            cout << "NO" << endln;
        }
    }
    
    return 0;
}