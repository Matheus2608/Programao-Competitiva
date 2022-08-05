#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    while (true) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        if (max({x1, y1, x2, y2}) == 0) return 0;
        else if (x1 == x2 && y1 == y2) cout << "0\n";
        else if(x1 == x2 or y1 == y2) cout << "1\n";
        else if(abs(x1 - x2) == abs(y1 - y2)) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}