#include<bits/stdc++.h>

using namespace std;
struct Node{
	long long data;
	Node* left;
	Node* right;
	
	Node(long long val){
		data = val;
		left = nullptr;
		right= nullptr;
			
	}
};
bool check_leaf_node(Node* root){
	return root && !root->left && !root->right;
}
void sum_of_right_node(Node* root,long long&sum){
	if(!root){
		return ;
	}
	
	if (root->right &&!root->right->left && !root->right->right) {
        sum += root->right->data;
    }
	sum_of_right_node(root->left, sum);
	sum_of_right_node(root->right, sum);
	
}

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		map<int, Node*> nodes;
		set<int> children;
		Node* root = NULL;
		for(int i = 0;i < n;i++){
			int u, v;
			cin >> u >> v;
			
			char c;
			cin >> c;
			if(nodes.find(u) == nodes.end()){
				(root) = new Node(u);
				if(c == 'L'){
					root->left = new Node(v);
					nodes[v] = root->left;
				}else if(c == 'R'){
					root->right = new Node(v);
					nodes[v] = root->right;
				}
				nodes[u] = (root);
			}else {
				if(c == 'L'){
					nodes[u]->left = new Node(v);
					nodes[v] = nodes[u]->left; 
				}else if(c == 'R'){
					nodes[u]->right = new Node(v);
					nodes[v] = nodes[u]->right;
				}
			}
			
		}
		
		if(root){
			long long sum = 0;
			sum_of_right_node(root, sum);
			cout << sum;
		}else{
			cout << 0;
		}
	
		nodes.clear();
		children.clear();
		cout << endl;
	}
}