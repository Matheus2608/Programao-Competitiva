#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m,clicks; cin >> n >> m;
	queue<pair<int,int>> fila;
	fila.push(make_pair(n,0));
	while(true){
		tie(n,clicks) = fila.front();fila.pop();
		if(n == m){
			cout << clicks << endl; return 0;
		}
		
		if(n < m){
			fila.push(make_pair(n*2,clicks+1));
		}
		
		if(n > 0) fila.push(make_pair(n-1,clicks+1));
		
	}
	
	return 0;
	
}
