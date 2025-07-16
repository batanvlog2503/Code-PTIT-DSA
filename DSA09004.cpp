#include<bits/stdc++.h>

using namespace std;


bool visited[1001];
void dfs(int u, vector<int> adj[]){
	cout << u << " ";
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v, adj);
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, m , u;
		cin >> n>> m >> u;
		vector<int> adj[1001];
		for(int i = 0; i <m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(u, adj);
		memset(visited, false, sizeof(visited));
		cout << endl;
	}
}