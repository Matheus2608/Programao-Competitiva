#include<bits/stdc++.h>

using namespace std;

int main(){
    int year;
    cin>>year;
    while(true){
        year+=1;
        int a = year/1000;//first digit
        int b = year/100 % 10;//2nd digit
        int c = year/10 %10;//3rd digit
        int d = year%10;
        if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
            cout<<year;
            return 0;
        }
    }
    return 0;
}