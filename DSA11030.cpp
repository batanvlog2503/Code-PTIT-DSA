
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

int bfs_node(int u, int v){
	queue<int> q;
	depth[u] = 0;
	q.push(u);
	visited[u] = true;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		for(int t : adj[x]){
			if(!visited[t]){
				q.push(t);
				visited[t] = true;
				depth[t] = depth[x] + 1;
				
			}
		}
	}
	return depth[v];
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
		int t;
		cin >> t;
		while(t--){
			memset(visited, false, sizeof(visited));
			memset(depth, 0, sizeof(depth));
			int u, v;
			cin >> u >> v;
			cout << bfs_node(u, v) << endl;
		}
	}
}


