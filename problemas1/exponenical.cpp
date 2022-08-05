#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

int fast_exp(int base, int e){
    if(e == 0)
	    return 1;
    if(e % 2)
	    return base * fast_exp(base * base,e/2);
    else
	    return fast_exp(base * base, e/2);
}

int main(){ sws;   

    /* Insira o codigo-fonte aqui */
    cout << fast_exp(2, 5) << endln;
    return 0;
}