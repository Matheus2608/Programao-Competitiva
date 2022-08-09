#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef tuple<int,int,int> tii;
 
int main()
{
    int n,m,k,l,r,x,y,d;
    vector<int> arr;
    
    scanf("%d %d %d",&n,&m,&k);
    
    arr.push_back(0);
    for(int i = 0; i < n; i++)
    {
        int aux;
        scanf("%d",&aux);
        arr.push_back(aux);
    }
    
    vector<ll> delta(m+2,0);
    vector<ll> delta2(n+2,0);
    vector<ll> psum(m+2,0);
    vector<ll> number_of_op(m+2,0);
    vector<tii> queries;
    
    queries.push_back(make_tuple(0,0,0));
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d",&l,&r,&d);
        queries.push_back(make_tuple(l,r,d));
    }
    
 
    for(int c = 0; c < k; c++)
    {
        scanf("%d %d",&x,&y);
        delta[x]++;
        delta[y+1]--;
    }
    
    ll atual = 0;
    for(int i = 1; i <= m; i++)
    {
        atual = atual + delta[i];
        number_of_op[i] = atual;
    }
    
    for(int i = 1; i <= m; i++)
    {
        l = get<0>(queries[i]);
        r = get<1>(queries[i]);
        d = get<2>(queries[i]);
        delta2[l] = delta2[l]+((ll) d)*number_of_op[i];
        delta2[r+1] = delta2[r+1]-((ll) d)*number_of_op[i];
    }
    
    ll ans=0;
    atual =0;
    for(int i = 1; i <= n; i++)
    {
        atual = atual + delta2[i];
        ans = atual + arr[i];
        printf("%lld ",ans);
    }
    printf("\n");
    
    return 0;
}