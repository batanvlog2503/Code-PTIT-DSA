#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
int n, m, s, t;
bool visited[1001];
int parent[1001];
void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : adj[v]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				parent[x] = v;
			}
		}
	}
}

int tplienthong(){
	int count = 0;
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			count++;
			bfs(i);
		}
	}
	return count;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		
		cin >> n>> m;
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	
		cout << tplienthong()<<endl;
	}
}