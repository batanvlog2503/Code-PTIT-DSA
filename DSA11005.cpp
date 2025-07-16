#include<bits/stdc++.h>

using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left= nullptr;
		right= nullptr;
	}
};
// cach giai bai toan
// phan tu dau tien trong level_order là level_order[0]
// khi ta cao level_order[0] thi t tim vi tri cua no trong inorder;
// ta se có 2 vector lưu leftIn rightIN, của inorder;
// vì level_order duyệt từ trái sang phải
// ta sẽ tìm kiếm phần tử left trong leftIn của levelorder;
// right cũng y hệt
// sau do ta sẽ buildtree(left_in, left_level) 
// voi left_level sẽ push_back(phần tử mà left_in tìm thầy trong levelorder)
// voi right_level sẽ push-back(phần tử mà right_in tìm thấy trong levelorder)

Node *buildTree(vector<int> &inorder, vector<int> &level_order){
	if(inorder.empty() || level_order.empty()){
		return nullptr;
	}
	
	int rootval = level_order[0];// vi phan tu ban dau cua level_order la root
	Node* root = new Node(rootval);
	
	auto it = find(inorder.begin(), inorder.end(), rootval); // tim vi tri cua root trong inorder;
	int idx = it - inorder.begin();
	
	vector<int> left_inorder(inorder.begin(), inorder.begin() + idx);
	vector<int> right_inorder(inorder.begin() + idx  +1, inorder.end()); // 
	// chia thanh 2 mang de xac dinh trai phai cua level_order;
	vector<int> left_level, right_level;
	for(int i = 1;i < level_order.size();i++){
		if(find(left_inorder.begin(), left_inorder.end(), level_order[i]) != left_inorder.end()){
			left_level.push_back(level_order[i]);
		}else if(find(right_inorder.begin(), right_inorder.end(), level_order[i]) != right_inorder.end()){
			right_level.push_back(level_order[i]);
		}
	}
	
	root->left = buildTree(left_inorder, left_level);
	root->right = buildTree(right_inorder, right_level);
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
		vector<int> inorder(n), level_order(n);
		
		for(int i =0 ;i < n;i++){
			cin >> inorder[i];
		}
		
		for(int i =0;i < n;i++){
			cin >> level_order[i];
		}
		
		Node* root = buildTree(inorder, level_order);
		
		postorder(root);
		cout << endl;
	}
}