// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
	
	int n = rand(1, 100);
	while(n--){
		int i = rand(1, 2);
		if(i == 1)
			cout << 'V';
		else cout << 'K';
	}
}

