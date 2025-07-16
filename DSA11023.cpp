
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
		right= nullptr;
	}
};
// hieu don gian khi duyetn theo inorder c?a BST se la day tang dan
bool check_inorder(vector<int> &inorder){
	for(int i = 0;i < inorder.size() - 1;i++){
		if(inorder[i] >= inorder[i + 1]){
			return false;
		}
	}
	return true;
}
Node* buildTree(vector<int> &preorder, int &idx, int min_val, int max_val){
	if(idx >= preorder.size()){
		return nullptr;
		
	}
	int val = preorder[idx];
	Node* root = new Node(val);
	if(val < min_val || val > max_val){
		return nullptr;
	}
	idx++;
	root->left = buildTree(preorder, idx, min_val, val - 1);
	root->right = buildTree(preorder, idx, val + 1, max_val);
	
	return root;
}

void dfs_BST(Node* root, int level, int &max_level){
	if(!root){
		return;
	}
	if(!root->left && !root->right){
		if(level > max_level){
			max_level = level;
		}
	}
	dfs_BST(root->left, level + 1, max_level);
	dfs_BST(root->right, level + 1, max_level);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> preorder(n);
		
		for(int i = 0;i < n;i++){
			cin >> preorder[i];
		}
		int level = 0;
		int idx =0;
		int max_level = INT_MIN;
		Node* root = buildTree(preorder, idx, INT_MIN, INT_MAX);
		dfs_BST(root, level, max_level);
		cout << max_level;
		
		cout << endl;
	}
}




