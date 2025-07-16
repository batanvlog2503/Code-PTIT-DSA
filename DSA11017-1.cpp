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
Node* buildtree_from_preorder(vector<int>& preorder, int &idx, int min_val, int max_val){
	if(idx >= preorder.size()){
		return nullptr;
	}
	int val = preorder[idx]; // đây là root;
	Node* root = new Node(val);
	if(val < min_val || val > max_val) return nullptr;
	
	idx++;
	root->left = buildtree_from_preorder(preorder, idx, min_val, val - 1);
	root->right = buildtree_from_preorder(preorder, idx, val + 1, max_val);
	
	return root;
}
Node* buildtree_from_postorder(vector<int> &postorder, int &idx, int min_val , int max_val){
	if(idx < 0){
		return nullptr;
	}
	// voi idx = n - 1;
	int val = postorder[idx];
	Node* root = new Node(val);
	
	if(val < min_val || val > max_val){
		return nullptr;
		
	}
	idx--;
	root->left = buildtree_from_postorder(postorder, idx,val+1, max_val);
	root->right = buildtree_from_postorder(preorder, idx, min_val, val - 1);
	
	return root;
	
}
Node* buildBSTFromInorder(vector<int>& inorder, int l, int r) {
    if (l > r) return nullptr;
	// giống hệt rìm kiếm nhị phân
    int mid = (l + r) / 2;
    Node* root = new Node(inorder[mid]);

    root->left = buildBSTFromInorder(inorder, l, mid - 1);
    root->right = buildBSTFromInorder(inorder, mid + 1, r);

    return root;
}
void postorder(Node* root){
	if(!root){
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
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
		
		int idx = 0;
		Node* root = buildtree_from_preorder(preorder, idx, INT_MIN, INT_MAX);
		postorder(root);
		
		cout << endl;
	}
}
