#include<bits/stdc++.h>

using namespace std;
vector<int> adj[1001];
bool visited[1001];
int out[1001];
int in[1001];
int n, m;
void dfs(int u){
	visited[u] = true;
	for(int x : adj[u]){
		if(!visited[x]){
			dfs(x);
		
		}
	}
	
}
bool tplienthong(){
	int count = 0;
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			count++;
			dfs(i);
		}
	}
	if(count == 1){
		return true;
	}
	return false;
}
bool check(){
	for(int i = 1;i <= n;i++){
		if(in[i] != out[i]){
			return false;
		}
	}
	return true;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(visited, false, sizeof(visited));
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			in[y]++;
			out[x]++;
		}
		dfs(1);
		
		
			if(check()){
				cout << 1;
			}else{
				cout << 0;
			}
	
		
		cout << endl;
		memset(adj, {}, sizeof(adj));
	}
}