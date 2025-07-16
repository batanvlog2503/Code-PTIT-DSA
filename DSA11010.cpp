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
bool check_leaf_node_same_order(Node* root, int level, int &leaf_level){
	if(!root) return true;
	
	if(!root->left && !root->right){
		if(leaf_level == -1){
			leaf_level = level;
		}
		return leaf_level == level;
	}
	
	return check_leaf_node_same_order(root->left, level + 1, leaf_level) && 
			check_leaf_node_same_order(root->right, level+1, leaf_level);
	
}

void check_two_nodes(Node* root, int &count){
	if(!root) return ;
	
	if ((root->left == nullptr) != (root->right == nullptr)) {
    	count++;
	}
	
	check_two_nodes(root->left, count);
	check_two_nodes(root->right, count);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		map<int, Node*> nodes;
		set<int> children;
		
		for(int i =0 ;i < n;i++){
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
			}else if(c== 'R'){
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
		int count = 0;
		check_two_nodes(root, count);
		if(count == 0 && check_leaf_node_same_order(root, 0, leaf_level)){
			cout << "Yes";
		}else{
			cout << "No";
		}
		cout << endl;
	}
}