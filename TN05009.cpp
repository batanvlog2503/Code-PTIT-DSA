#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[1002];
bool visited[1002];
int parent[1002];
int st, en, m;
bool ok;
void dfs(int u){
	visited[u] = true;
	if(ok == true){
		return;
	}
	for(int x : adj[u]){
		if(!visited[x]){
			parent[x] = u;
			dfs(x);
		}else if(x != parent[u] && x == 1){
			ok = true;
			st = u;
			en = x;
			break;
		}
	}

}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i = 0;i <m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			
		}
		for(int i = 0;i < n;i++){
			sort(adj[i].begin(), adj[i].end());
		}
		ok = false;
		dfs(1);
		if(ok){
			vector<int> path;
			path.push_back(1);
				while(st != en){
					path.push_back(st);
					st = parent[st];
					
				}
				path.push_back(1);
				reverse(path.begin(), path.end());
				
				
					for(int x : path){
						cout <<x << " ";
					}
		}else{
			cout << "NO";
		}
		cout << endl;
		memset(visited, false, sizeof(visited));
		memset(adj, {}, sizeof(adj));
		memset(parent, 0, sizeof(parent));
	}
}