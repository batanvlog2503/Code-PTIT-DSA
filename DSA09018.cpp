#include<bits/stdc++.h>

using namespace std;


vector<int> adj[1001];
bool visited[1001];
int n, m;
vector<int> tmp;
void dfs(int u){
	visited[u] = true;
	for(int x : adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}

void lietkedinhtru(){
	for(int i = 1;i <= n;i++){
		memset(visited, false, sizeof(visited));
		int ans = 0;
		visited[i] = true;
		for(int j =1;j <= n;j++){
			if(!visited[j]){
				ans++;
				dfs(j);
				if(ans > 1){
					tmp.push_back(i);
					break;
				}
			}
		}
		
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		memset(adj, {}, sizeof(adj));
		memset(visited ,false, sizeof(visited));
		tmp.clear();
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			
			adj[x].push_back(y);
			adj[y].push_back(x);
			
		}
		lietkedinhtru();
		
		for(int x : tmp){
			cout << x << " ";
		}
		cout << endl;
		
	}
}