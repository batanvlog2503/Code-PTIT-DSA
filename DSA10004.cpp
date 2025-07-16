#include<bits/stdc++.h>

using namespace std;
int in[1002];
int out[1002];
vector<int> adj[1002];
bool visited[1002];
int n, m;
bool check_euler(){
	for(int i = 1;i <= n;i++){
		if(in[i] % 2 == 1){
			return false;
		}
	}
	return true;
}
bool check_half_euler(){
	int count = 0;
	for(int i = 1;i <= n;i++){
		if(in[i] % 2 == 1){
			count++;
			if(count > 2){
				return false;
			}
		}
	}
	if(count ==2){
		return true;
	}
	return false;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		memset(adj,{}, sizeof(adj));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(visited, false, sizeof(visited));
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			
			adj[x].push_back(y);
			adj[y].push_back(x);
			in[x]++;
			in[y]++;
		}
		
		if(check_euler()){
			cout << 2 ;
		}else if(check_half_euler()){
			cout << 1;
		}else{
			cout << 0;
		}
		cout << endl;
		
	}
}