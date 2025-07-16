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

void level_order(Node* root){
	if(!root){
		return;
		
	}
	
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty()){
		Node* curr = q.front();
		q.pop();
		
		cout << curr->data <<" ";
		
		if(curr->left) q.push(curr->left);
		if(curr->right) q.push(curr->right);
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		map<int, Node*>	nodes;
		set<int> children;
		for(int i = 0;i< n;i++){
			int u, v;
			cin >> u >> v;
			char c;
			cin >> c;
			
			if(nodes[u] == nullptr){
				nodes[u] = new Node(u);
			}
			if(nodes[v] == nullptr){
				nodes[v] = new Node(v);
			}
			
			if(c == 'L'){
				nodes[u]->left = nodes[v];
			}else if(c == 'R'){
				nodes[u]->right = nodes[v];
			}
			
			children.insert(v);
		}
		
		Node* root = NULL;
		for(auto it : nodes){
			if(children.find(it.first) == children.end()){
				root = it.second;
				break;
			}
		}
		
		lever_order(root);
		cout << endl;
	}
}