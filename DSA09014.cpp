#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1002];
bool visited[1002];

int parent[1002];
// cách 1
bool dfs(int u, int par){
	visited[u] = true;
	
	for(int x : adj[u]){
		if(!visited[x]){
			if(dfs(x, u)) return true;
		}else if(x != par){
			return true;
		}
	}
	return false;
}
// cách 2
bool bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] =true;
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
		memset(parent, 0, sizeof(parent));
		for(int i = 0 ;i < m;i++){
			int x, y;
			cin >> x >>y ;
			adj[y].push_back(x);
			adj[x].push_back(y);
			
		}
		bool check = true;
		for(int i = 1; i <= n;i++){
			if(!visited[i]){
				if(bfs(i)){
					check = false;
					break;
				}
			}
		}
		
		if(check == false){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << endl;
		
	}
}