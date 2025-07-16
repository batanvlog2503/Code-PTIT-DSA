#include<bits/stdc++.h>

using namespace std;

// nhap va duyet cay

struct Node {
	int data;
	
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = nullptr;
		right=  nullptr;
	}
};
void inorder(Node* root){
	if(!root){
		return ;
		
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void level_order_spiral(Node* root){
	if(!root){
		return ;
	}
	queue<Node*> q;
	q.push(root);
	bool left_to_right = true;
	
	while(!q.empty()){
		int n = q.size();
		vector<int> level;
		
		for(int i =0 ;i < n;i++){
			Node* cur = q.front();
			q.pop();
			level.push_back(cur->data);
			
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
		
		if(left_to_right == true){
			reverse(level.begin(), level.end());
		}
		
		for(int val : level){
			cout << val << " ";
		}
		
		left_to_right = !left_to_right;
	}
}
int main(){
	int T;
	cin >> T;
	
	while(T--){
		int n;
		cin >> n;
		
		map<int, Node*> nodes;
		set<int> children;
		
		for(int i = 0;i < n;i++){
			int u, v;
			char x;
			cin >> u >> v >> x;
			
			if(nodes[u] == nullptr){
				nodes[u] = new Node(u);
			}
			if(nodes[v] == nullptr){
				nodes[v] = new Node(v);
			}
			if(x == 'L'){
				nodes[u]->left = nodes[v];
			}else if(x == 'R'){
				
				nodes[u]->right = nodes[v];
			}
			
			children.insert(v); // kieu chi tim phan tu con thoi
		}
		
		Node* root  = nullptr;
		
		for(auto pair: nodes){
			if(children.find(pair.first) == children.end()){
				root = pair.second;
				break;
			}
		}
		
		// hieu don gian tim root bat dau tu dau
		
		level_order_spiral(root);
		cout << endl;
	}
	
}