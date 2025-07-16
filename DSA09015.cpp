#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1002];
bool visited[1002];
int parent[1001];
int color[1001];
bool color_dfs(int u){
	color[u] = 1; // đang duyệt
	
	for(int x : adj[u]){
		if(color[x] == 0){
			parent[x] = u;
			if(color_dfs(x)){
				return true;
			}
		}else if(color[x] == 1){
			// tồn tại canhkj ngược
			return true;
		}
	}
	color[u] = 2;
	// đã duyệt xong
	return false;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		memset(adj, {}, sizeof(adj));
		memset(visited, false, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		memset(color, 0, sizeof(color));
		
		for(int i = 0 ;i < m;i++){
			int x, y;
			cin >> x >>y ;
			adj[y].push_back(x);
			//adj[x].push_back(y);
			
		}
		bool check = true;
		for(int i = 1; i <= n;i++){
			if(color[i] == 0){
				if(color_dfs(i)){
					check = false;
					break;
				}
			}
		}
		
		if(check == false){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << endl;
		
	}
}