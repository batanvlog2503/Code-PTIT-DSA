#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1001];
int a[1002][1002];
bool visited[1002];
int color[1002];

bool dfs_color(int u){
	color[u] = 1; // trang thai duyet
	
	for(int x : adj[u]){
		if(color[x] == 0){
			if(dfs_color(x)) return true;
		}else if(color[x] == 1){
			return true;
		}
	}
	color[u] = 2;
	return false;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		memset(adj , {}, sizeof(adj));
		memset(a, 0, sizeof(a));
		memset(visited, false, sizeof(visited));
		memset(color, 0, sizeof(color));
		
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			
			adj[x].push_back(y);
		//	adj[y].push_back(x);
			
		}
		
		int ok = 0;
		for(int i = 1;i <= n;i++){
			if(color[i] == 0){
				if(dfs_color(i)){
					cout << "YES";
					ok = 1;
					break;
				}
			}
		}
		if(ok == 0){
			cout << "NO";
		}
		cout << endl;
	}
}