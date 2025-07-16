#include<bits/stdc++.h>

using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = nullptr;
		right= nullptr;
			
	}
};

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
		
		for(int i = 0;i < n;i++){
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
			if(c == 'R'){
				nodes[u]->right = nodes[v];
			}else if(c == 'L'){
				nodes[u]->left = nodes[v];
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
		
		int count =0;
		check_two_nodes(root, count);
		if(count == 0){
			cout << 1;
		}else{
			cout << 0;
		}
		cout << endl;
	}
}