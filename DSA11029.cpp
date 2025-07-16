
#include<bits/stdc++.h>
// tìm đường đi lớn nhất từ node gốc sang gốc khác BFS
using namespace std;
vector<int> adj[100001];
bool visited[100001];
int depth[100001];
int parent[100001];
const int MOD = 1e9 + 7;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = right = nullptr;
	}
};
void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			visited[v] = true;
			parent[v] = u;
			dfs(v);
			
		}
	}
}

void path(int u, int v){
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	dfs(u);
	
	vector<int> paths;
	
	while(v != u){
		paths.push_back(v);
		v = parent[v];
	}
	paths.push_back(u);
	reverse(paths.begin(), paths.end());
	for(int x : paths){
		cout << x << " ";
	}
	cout << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		map<int, Node*> nodes;
		Node* root = NULL;
		memset(visited, false, sizeof(visited));
		memset(depth, 0, sizeof(depth));
		memset(adj, {}, sizeof(adj));
		memset(parent, 0, sizeof(parent));
		set<int > s;
		for(int i =0 ;i < n - 1;i++){
			int u, v;
			cin >> u >> v;
			if(s.find(u) == s.end()){
				s.insert(u);
			}
			adj[u].push_back(v);
			adj[v].push_back(u);
			
		}
		vector<int> tmp;
		for(int i = 1;i <= n;i++){
			if(s.find(i) == s.end()){
				tmp.push_back(i);
			}
		}
		
		for(int t : tmp){
			path(1, t);
		}
		
		
		
	}
}

