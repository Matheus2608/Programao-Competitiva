#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned int v = 4;     // input bits to be reversed
    unsigned int r = v; // r will be reversed bits of v; first get LSB of v
    int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end

    for (v >>= 1; v; v >>= 1)
    {   
    r <<= 1;
    r |= v & 1;
    s--;
    }
    r <<= s;

    cout << r << "\n";
    return 0;
}