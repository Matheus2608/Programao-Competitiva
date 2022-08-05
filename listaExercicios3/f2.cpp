#include <bits/stdc++.h> // Include every standard library
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
 
 
int distancia_euclidiana(int a, int b){
    return pow((a - b), 2);
}
int main(){
    sws;
    int n, k1, k2; cin >> n >> k1 >> k2;
    ll a[n], b[n], distancia;
    
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n) cin >> b[i];
    
    int i = 0;
    while(true){
        if(k1 == 0 or i == n) break;
        distancia = abs(a[i] - b[i]);
        if(distancia >= k1){
            if(a[i] > b[i]) a[i]-= k1;
            else a[i]+=k1;
            k1 = 0;
            break;
        }else{
            if(a[i] > b[i]) a[i] -= distancia;
            else a[i]+=distancia;
            k1-=distancia;
        }
        i++;
    }

    i = 0;
    k1 = k1 % n;
    while(k1){
        a[i]++;
        k1--;
    }


    i = 0;
    while(true){
        if(k2 == 0 or i == n) break;
        distancia = abs(a[i] - b[i]);
        if(distancia >= k2){
            if(b[i] > a[i]) b[i]-= k2;
            else b[i]+=k2;
            k2 = 0;
            break;
        }else{
            if(b[i] > a[i]) b[i] -= distancia;
            else b[i]+=distancia;
            k2-=distancia;
        }
        i++;
    }

    i = 0;
    k2 = k2 % n;
    while(k2){
        b[i]++;
        k2--;
    }

 
    ll res = 0;
    FOR(i,0,n){
        res += distancia_euclidiana(a[i], b[i]);
    }
    cout << res << endl;
    return 0;
}