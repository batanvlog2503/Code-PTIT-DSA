
#include<bits/stdc++.h>

using namespace std;

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

Node* buildTree_from_inorder(vector<int> &arr, int l, int r){
	if(l > r){
		return nullptr;
	}
	int m = (l + r) / 2;
	int val = arr[m];
	Node* root = new Node(val);
	
	root->left= buildTree_from_inorder(arr, l,m-1);
	root->right = buildTree_from_inorder(arr, m + 1, r);
	
	return root;
}

void preorder(Node* root){
	if(!root){
		return ;
	}
	cout << root->data <<  " ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root){
	if(!root){
		return ;
	}
	postorder(root->left);
	postorder(root->right );
	cout << root->data << " ";
}

void find_leaf_nodes(Node* root, vector<int> & tmp){
	// di tim node lá;
	if(!root){
		return ;
	}
	
	if(!root->right && !root->left){
		tmp.push_back(root->data);
		return;
	}
	if(root->left){
		find_leaf_nodes(root->left, tmp);
	}
	if(root->right ){
		find_leaf_nodes(root->right, tmp);
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> BST(n);
		for(int i = 0;i < n;i++){
			cin >> BST[i];
		}
		sort(BST.begin(), BST.end());
		Node* root = buildTree_from_inorder(BST, 0, n - 1);
		vector<int> tmp;
		find_leaf_nodes(root, tmp);
		cout << tmp.size() ;
	
		cout << endl;
	}
}

