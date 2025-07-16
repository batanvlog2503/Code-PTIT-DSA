#include<iostream>
#include<bits/stdc++.h>


using namespace std;
vector<int> adj[1001];

bool visited[1001];

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] =true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v <<" ";
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				
			}
		}
	}
}
void dfs(int u){
	cout << u << " ";
	visited[u] = true;
	for(int x : adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int v, e, u;
		cin >> v >> e >> u;
		for(int i = 1;i <= v;i++){
			adj[i].clear();
		}
		for(int i = 0 ;i < e;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
//			adj[y].push_back(x);
		}
		memset(visited, false, sizeof(visited));
		bfs(u);
		cout << endl;
	}
}