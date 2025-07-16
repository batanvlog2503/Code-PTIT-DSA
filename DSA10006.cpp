#include<bits/stdc++.h>

using namespace std;


bool visited[1001];
int a[1001][1001];
int n, m, u;
vector<int> adj[1002];
void dfs1(int u){
	visited[u] = true;
	for(int x : adj[u]){
		if(!visited[x]){
			dfs1(x);
		}
	}
}
bool tplt(){
	int count = 0;
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			count++;
			dfs1(i);
		}
	}
	if(count == 1){
		return true;
	}
	return false;
}
void dfs(int u, vector<pair<int, int>> &T){
	visited[u] = true;
	for(int x : adj[u]){
		if(!visited[x]){
			T.push_back({u, x});
			dfs(x, T);
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m >> u;
		memset(visited, false, sizeof(visited));
		memset(a, 0, sizeof(a));
		memset(adj, {}, sizeof(adj));
		vector<pair<int, int>> T;
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(u, T);
		if(T.size() < n - 1){
			cout << -1 << endl;
		}else if(T.size() == n-1){
			memset(visited, false, sizeof(visited));
			if(tplt()){
				for(auto it : T){
					cout << it.first << " " << it.second <<endl;
				}
			}else{
				cout << -1 << endl;
			}
		}
		
	}
}