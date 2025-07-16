#include<bits/stdc++.h>

using namespace std;


bool visited[1001];
vector<int> adj[1001];
int n, m, s, t;
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
				q.push(x);
				visited[x] = true;
				parent[x] = v;
			}
		}
	}
}

void path(int s, int t){
	memset(parent, 0, sizeof(parent));
	memset(visited, false, sizeof(visited));
	bfs(s);
	
	if(!visited[t]){
		cout << -1;
	}else{
		
		vector<int> paths;
		
		while(t != s){
			paths.push_back(t);
			t = parent[t];// tìm cha của nó
		}
		paths.push_back(s); // thoát vòng while chưa kịp cập nhật s
		
		for(int i = paths.size() - 1;i >= 0;i--){
			cout << paths[i] <<" ";
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m >> s >> t;
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		path(s, t);
		cout << endl;
		memset(adj, {}, sizeof(adj));
	}
}