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

unordered_map<int, int> inorderIndex;
Node* buildTree(vector<int> &preorder, int prestart, int preend, 
				vector<int> &inorder, int instart, int inend){
	if(prestart > preend || instart > inend){
		return nullptr;
	}			
	
	int rootval = preorder[prestart]; // phan tu goc dau tien
	Node* root = new Node(rootval);
	int rootIndex = inorderIndex[rootval] ; // vi tri goc
	
	int leftsize = rootIndex-instart;// dem xem bao nhieu phan tu trai
	
	root->left = buildTree(preorder, prestart + 1, prestart + leftsize,
						inorder, instart, rootIndex - 1);
	root->right = buildTree(preorder, prestart + 1 + leftsize, preend,
						inorder, rootIndex + 1, inend);
						
	return root;
		
}

void postorder(Node* root){
	if(!root){
		return;
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
		vector<int> preorder(n), inorder(n);
		
		for(int i = 0;i < n;i++){
			cin >> inorder[i];
		}
		for(int i = 0;i < n;i++){
			cin >> preorder[i];
		}
		inorderIndex.clear();
		for(int i = 0;i < n;i++){
			inorderIndex[inorder[i]] = i;
		}
		
		Node* root = buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
		
		postorder(root);
		cout << endl;
	}
}