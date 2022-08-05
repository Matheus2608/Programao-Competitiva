#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

void print_array(int a[], int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endln;
}

int main(){ sws;   
    /* Insira o codigo-fonte aqui */
    int n;
    cin >> n;
    int first, second, third, fourth;
    int winners[2];
    for (int i=0; i<n; i++){
        cin >> first >> second >> third >> fourth;
        winners[0] = max(first, second);
        winners[1] = max(third, fourth);
        sort(winners, winners+2, greater<>());
        int tmp[] = {first, second, third, fourth};
        sort(tmp, tmp+4, greater<>());
        //print_array(winners, 2);
        //print_array(tmp, 4);
        if (winners[0] != tmp[0] or winners[1] != tmp[1]) cout << "NO" << endln;
        else cout << "YES" << endln;
    }
    return 0;
}