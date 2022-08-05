#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define endln "\n"

int main(){ sws;   

    /* Insira o codigo-fonte aqui */
    int array[] = {10, 35, 85, 93, 62, 77, 345, 43, 2, 10}; 
    int n = sizeof(array)/sizeof(array[0]); 
    // 'sizeof' gives the size of total array i.e. size of each character * no. of characters
    // so to get no. of characters
    // we divide the sizeof(array) with the size of any one character of the array
    // here it is array[0]
    sort(array, array+n);   
    cout << "Array after sorting using "
    "default sort is : "; 
    for (int i = 0; i < n; ++i) 
    cout << array[i] << " " << endln;   
    return 0; 
}