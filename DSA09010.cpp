#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1002];
bool visited[1002];
int n, m;
int bfs(int u){
	queue<int> q;
	int dem = 0;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		dem++;
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
	return dem;
}
int main(){
	int q;
	cin >> q;
	
	while(q--){
		cin >> n >> m;
		
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y); // đồ thị có hướng
			
		}
		
		if(bfs(1) == n){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << endl;
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
	}
}