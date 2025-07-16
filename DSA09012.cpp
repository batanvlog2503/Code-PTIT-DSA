#include<bits/stdc++.h>

using namespace std;
int a[1002][1002];
bool visited[1002];
vector<int> tmp[1002];
int b[1002][1002];
vector<int> peak;
int n, m;
void dfs(int u){
	visited[u] = true;
	for(int i = 1;i <= n;i++){
		if(!visited[i] && a[u][i]){
			dfs(i);
		}
	}
}

void tplt(){
	int count = 0;
	for(int i = 1;i <= n;i++){
		memset(visited, false, sizeof(visited));
		int ans= 0;
		visited[i] = true;
		for(int j = 1;j <= n;j++){
			if(!visited[j]){
				ans++;
				dfs(j);
				if(ans > 1){
					peak.push_back(i);
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
		memset(a, 0, sizeof(a));
		memset(visited, false, sizeof(visited));
		peak.clear();
		cin >> n >> m;
		for(int i = 0;i < m;i++){
			int x,y;
			cin >> x >> y;
			a[x][y] = a[y][x] = 1;
		
		}
		tplt();
		if(!peak.empty()){
			for(int x : peak){
				cout << x <<" ";
			}
		}
		cout << endl;
		
		
	}
}