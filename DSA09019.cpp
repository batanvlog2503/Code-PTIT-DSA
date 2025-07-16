#include<bits/stdc++.h>

// kiem tra chu trinh

using namespace std;

vector<int> adj[1002];
bool visited[1002];
int n, m;
int parent[1002];

bool cycle_dfs(int u){
	visited[u] = true;
	for(int x  : adj[u]){
		if(!visited[x]){
			parent[x] = u;
			if(cycle_dfs(x)) return true;
		}else if(x != parent[u]){
			return true;
		}
	}
	return false;
}

bool cycle_bfs(int u){
	int dem = 0;
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				parent[x] = v;
			}else if(x != parent[v]){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
		for(int  i = 0; i < m;i++){
			int x, y;
			cin >> x >> y;
			
			adj[x].push_back(y);
			adj[y].push_back(x);
			
		}
		int ok = 0;
		for(int i = 1;i <= n;i++){
			if(!visited[i]){
				if(cycle_bfs(i)){
					cout <<"YES";
					ok = 1;
					break;
				}
			}
		}
		if(ok == 0){
			cout << "NO";
		}
		cout << endl;
		
	}
}