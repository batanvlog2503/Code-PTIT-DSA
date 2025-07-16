#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left  = nullptr;
		right = nullptr;
	}	
};


set<int> s;
Node* buildNode(Node* root, int val){
	if(!root) return root = new Node(val);
	
	if(val < root->data){
		root->left = buildNode(root->left, val);
	}else{
		root->right = buildNode(root->right, val);
		
	}
	return root;
}

void inorder(Node* root){
	if(!root) return;
	
	inorder(root->left);
	cout << root->data<<" ";
	inorder(root->right);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		for(int i =0 ;i < n;i++){
			int u, v;
			char c;
			cin >> u >> v >> c;
			s.insert(u);
			s.insert(v);
		}
		Node* root = NULL;
		for(int val : s){
			root = buildNode(root, val);
		}
		inorder(root);
		cout << endl;
		s.clear();
	}
}