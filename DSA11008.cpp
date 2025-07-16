#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
	
};
// dfs
bool check_leaf_node_same_order_bfs(Node* root){
	if(!root) return true;
	
	queue<pair<Node*, int>> q;
	q.push({root, 0}); // luu root voi level cua no
	
	int leaf_level = -1;
	
	while(!q.empty()){
		Node* cur = q.front().first;
		int level = q.front().second;
		
		q.pop();
		if(!cur->left && !cur->right){
			if(leaf_level == -1){
				leaf_level = level;
			}else if(leaf_level != level){
				return false;
			}
			
		}
		
		if(cur->left){
			q.push({cur->left, level+1});
		}
		if(cur->right){
			q.push({cur->right, level+1});
		}
		return true;
	}
}
bool check_leaf_node_same_order(Node* root, int level, int &leaf_level){
	if(!root) return true; // nghĩa là root rỗng
	
	if(!root->left && !root->right){
		if(leaf_level == -1){
			leaf_level = level;
		}
		
		if(leaf_level == level){
			return true;
		}else{
			return false;
		}
	}
	
	return check_leaf_node_same_order(root->left, level + 1, leaf_level) && 
			check_leaf_node_same_order(root->right, level + 1, leaf_level);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		map<int, Node*>	nodes;
		set<int> children;
		for(int i = 0;i< n;i++){
			int u, v;
			cin >> u >> v;
			char c;
			cin >> c;
			
			if(nodes[u] == nullptr){
				nodes[u] = new Node(u);
			}
			if(nodes[v] == nullptr){
				nodes[v] = new Node(v);
			}
			
			if(c == 'L'){
				nodes[u]->left = nodes[v];
			}else if(c == 'R'){
				nodes[u]->right = nodes[v];
			}
			
			children.insert(v);
		}
		
		Node* root = NULL;
		for(auto it : nodes){
			if(children.find(it.first) == children.end()){
				root = it.second;
				break;
			}
		}
		int leaf_level = -1;
		if(check_leaf_node_same_order(root, 0, leaf_level)){
			cout << 1;
		}else{
			cout << 0;
		}
		
		cout << endl;
	}
}