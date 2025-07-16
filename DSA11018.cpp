#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left = nullptr;
		right=nullptr;
	}
};

Node* buildtree_from_levelorder_BST(Node* root, int val){
	if(!root) return new Node(val);
	
	if(val < root -> data){
		root->left = buildtree_from_levelorder_BST(root->left, val);
		
	}else{
		root->right = buildtree_from_levelorder_BST(root->right, val);
	}
	
	return root;
}
void preorder(Node* root){
	if(!root){
		return ;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> level_order(n);
		
		for(int i = 0;i < n;i++){
			cin >> level_order[i];
		}
		
		Node* root = NULL;
		for(int val : level_order){
			root = buildtree_from_levelorder_BST(root, val);
		}
		
		preorder(root);
		cout << endl;
	}
}


