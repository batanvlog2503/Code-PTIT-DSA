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

void path(){
	memset(parent, 0, sizeof(parent));
	memset(visited, false, sizeof(visited));
	bfs(s);
	stack<int> st;
	if(!visited[t]){
		cout << -1;
	}else{
		while(t != s){
			st.push(t);
			t = parent[t];
		}
		st.push(s);
		while(!st.empty()){
			cout << st.top() <<" ";
			st.pop();
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		
		cin >> n>> m>> s>> t;
		memset(adj, {}, sizeof(adj));
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		path();
		cout << endl;
		
	}
}