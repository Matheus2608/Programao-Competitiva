// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull rand(ull a, ull b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    ull n = rand(1, 1e18);
    cout << n << endl;
    return 0;
}