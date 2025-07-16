
#include<bits/stdc++.h>
// tìm đường đi lớn nhất từ node gốc sang gốc khác BFS
using namespace std;
vector<int> adj[100001];
bool visited[100001];
int depth[100001];
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
int max_distance_node(int start_){
	depth[start_] = 0;
	queue<int> q;
	q.push(start_);
	
	visited[start_] = true;
	int max_distance = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v]){
				visited[v] = true;
				depth[v] = depth[u] + 1;
				max_distance = max(max_distance, depth[v]);
				q.push(v);
			}
		}
		
	}
	return max_distance;
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
		for(int i =0 ;i < n - 1;i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			
		}
		cout << max_distance_node(1) << endl;
	}
}

