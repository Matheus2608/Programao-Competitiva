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

int distancia_euclidiana(int a, int b)
{
    return pow((a - b), 2);
}
int main()
{
    sws;
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    ll a[n], b[n], distancia;
    priority_queue<int> pq_max;

    FOR(i, 0, n)
        cin >> a[i];
    FOR(i, 0, n)
        cin >> b[i];

    // sort(a,a+n, greater<int>());
    // sort(b,b+n, greater<int>());

    FOR(i, 0, n)
    {
        pq_max.push(abs(a[i] - b[i]));
    }

    int i;
    ll tmp;
    while (k1--)
    {
        tmp = pq_max.top();
        pq_max.pop();
        pq_max.push(tmp-1);
    }

    while (k2--)
    {
        tmp = pq_max.top();
        pq_max.pop();
        pq_max.push(tmp-1);
    }

    ll res = 0;
    while(!pq_max.empty()){
        tmp = pq_max.top();pq_max.pop();
        res += (tmp * tmp);
    }
    cout << res << endl;
    return 0;
}
