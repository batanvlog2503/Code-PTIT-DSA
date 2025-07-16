#include<bits/stdc++.h>

using namespace std;
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
vector<int> n1;
vector<int> n2;
void postorder1(Node* root1){
	if(!root1){
		return ;
	}
	postorder1(root1->left);
	postorder1(root1->right);
	n1.push_back(root1->data);
}
void postorder2(Node* root2){
	if(!root2){
		return ;
	}
	postorder2(root2->left);
	postorder2(root2->right);
	n2.push_back(root2->data);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		 int n, m;
		 cin >> n;
		 map<int, Node*> nodes1, nodes2;
		 set<int> children1, children2;
		 
		 for(int i = 0;i < n;i++){
		 	int u, v;
		 	cin >> u >> v;
		 	char c;
		 	cin >> c;
		 	if(nodes1[u] == nullptr){
		 		nodes1[u] = new Node(u);
			}
			if(nodes1[v] == nullptr){
				nodes1[v] = new Node(v);
			}
			if(c == 'L'){
				nodes1[u]->left = nodes1[v];
				
			}else if(c == 'R'){
				nodes1[u]->right = nodes1[v];
			}
			children1.insert(v);
			
		 }
		 
		 Node* root1 = NULL;
		 for(auto it : nodes1){
		 	if(children1.find(it.first) == children1.end()){
		 		root1 = it.second;
		 		break;
			 }
		 }
		 postorder1(root1);
		 cin >> m;
		 for(int i = 0;i < m;i++){
		 	int u, v;
		 	cin >> u >> v;
		 	char c;
		 	cin >> c;
		 	if(nodes2[u] == nullptr){
		 		nodes2[u] = new Node(u);
			}
			if(nodes2[v] == nullptr){
				nodes2[v] = new Node(v);
			}
			if(c == 'L'){
				nodes2[u]->left = nodes2[v];
				
			}else if(c == 'R'){
				nodes2[u]->right = nodes2[v];
			}
			children2.insert(v);
			
		 }
		 
		 Node* root2 = NULL;
		 for(auto it : nodes2){
		 	if(children2.find(it.first) == children2.end()){
		 		root2 = it.second;
		 		break;
			 }
		 }
		 postorder2(root2);
		 if(n != m){
		 	cout << 0;
		 }else{
		 	int ok = 1;
		 	for(int i = 0;i < n1.size();i++){
		 		if(n1[i] != n2[i]){
		 			cout << 0;
		 			ok = 0;
		 			break;
				 }
			 }
			 if(ok == 1){
			 	cout << 1;
			 }
		 }
		 cout << endl;
			
	}
}