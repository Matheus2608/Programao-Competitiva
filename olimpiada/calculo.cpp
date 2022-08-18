#include<bits/stdc++.h>
using namespace std;
int soma_digitos(int x){
    int soma = 0;
    while(x){
        soma += x % 10;
        x /= 10;
    }

    return soma;
}
int main(){
    int s, a, b, res = 0;
    cin >> s >> a >> b;
    for(int i = a; i <= b; i++){
        if(soma_digitos(i) == s) res++;
    }
    cout << res << endl;
    return 0;
}