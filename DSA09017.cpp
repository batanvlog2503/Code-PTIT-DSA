#include<bits/stdc++.h>

using namespace std;

// cây là 1 đồ thị vô hướng ,liên thông và không có chu trình

int deg[1002];
int n;
vector<int> adj[1001];
bool visited[1002];
int in[1001];
bool dfs_cycle(int u){
	queue<int> q;
	
	for(int i = 1;i <= n;i++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	int count = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : adj[v]){
			in[x]--;
			if(in[x] == 0){
				q.push(x);
			}
		}
	}
	return count == n;
}

bool bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	int dem = 0;
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
	if(dem == n){
		return true;
	}
	return false;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n;
		memset(adj, {}, sizeof(adj));
		memset(in, 0, sizeof(in));
		memset(visited, false, sizeof(visited));
		for(int i = 0;i < n - 1;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			in[x]++;
			in[y]++;
			
		}
		if(bfs(1)){
			if(!dfs_cycle(1)){
				cout << "YES";
			}else{
				cout << "NO";
			}
		}else{
			cout << "NO";
		}
		cout << endl;
		
	}
}