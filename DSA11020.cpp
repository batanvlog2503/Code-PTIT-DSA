
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
// hieu don gian khi duyetn theo inorder c?a BST se la day tang dan
bool check_inorder(vector<int> &inorder){
	for(int i = 0;i < inorder.size() - 1;i++){
		if(inorder[i] >= inorder[i + 1]){
			return false;
		}
	}
	return true;
}

bool check_preorder(vector<int> &preorder){
	stack<int> st;
	int min_allow = INT_MIN;
	
	for(int val: preorder){
		if(val < min_allow){
			return false;
		}
		
		while(!st.empty() && val > st.top()){
			min_allow = st.top();
			st.pop();
		}
		st.push(val);
	}
	
	return true;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> inorder(n);
		
		for(int i = 0;i < n;i++){
			cin >> inorder[i];
		}
		
		if(check_inorder(inorder)){
			cout << 1;
		}else{
			cout << 0;
		}
		cout << endl;
	}
}

