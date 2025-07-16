#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		
	}
}
Node* buildtree_from_preorder(vector<int>& preorder, int &idx, int min_val, int max_val){
	if(idx >= preorder.size()){
		return nullptr;
	}
	int val = preorder[idx]; // đây là root;
	if(val < min_val || val > max_val) return ;
	
	idx++;
	root->left = buildtree_from_preorder(preorder, idx, min_val, val - 1);
	root->right = buildtree_from_preorder(preorder, idx, val + 1, max_val);
	
	return root;
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
		
		Node* root = buildtree_from_preorder(preorder, 0, INT_MIN, INT_MAX);
		
		
		
	}
}
