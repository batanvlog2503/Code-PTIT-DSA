#include<bits/stdc++.h>

using namespace std;
int n, m;
bool visited[1001];
vector<int> adj[1001];

vector<vector<int>> component;
vector<int> res;
void dfs(int u){
	
	visited[u] = true;
	res.push_back(u);
	for(int x : adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}
void tplienthong(){
	int count = 0;
	component.clear();
	
	memset(visited, false, sizeof(visited));
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			res.clear();
			dfs(i);
			component.push_back(res);
		}			
	}
}
 bool check(int x, int y){
 	for(vector<int> it: component){
 		if(find(it.begin(), it.end(), x) != it.end() && find(it.begin(), it.end(), y) != it.end()){
 			return true;
		 }
	 }
	 return false;
 }

int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		tplienthong();
		int t;
		cin >> t;
		while(t--){
			int x, y;
			cin >> x >> y;
			if(check(x, y)){
				cout << "YES";
			}else{
				cout <<"NO";
			}
			cout << endl;
		}
		memset(adj, {}, sizeof(adj));
	}
}