#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[1002][1002];
bool visited[1001];
vector<pair<int,int>> tmp;

void dfs(int u){
	visited[u] = true;
	for(int i = 1;i <= n;i++){
		if(!visited[i] && a[u][i]){
			dfs(i);
			
		}
	}
}

bool kiemtralienthong(){
	int count = 0;
	for(int i = 1;i <= n;i++){
		if(!visited[i]){
			count++;
			dfs(i);
			if(count > 1){
				return true;
			}
			
		}
	}
	
	return false;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		memset(a, 0, sizeof(a));
		memset(visited, false, sizeof(visited));
		
		cin >> n >> m;
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			tmp.push_back({x, y});
			a[x][y] = a[y][x] = 1;
		}
		for(int i = 0;i < tmp.size();i++){
			int x = tmp[i].first;
			int y = tmp[i].second;
			
			a[x][y] = a[y][x] = 0;
			if(kiemtralienthong()){
				cout << x <<" " << y << " ";
			}	
			a[x][y] = a[y][x] = 1;
			memset(visited, false, sizeof(visited));
			
		}
		tmp.clear();
		cout << endl;
	}
}