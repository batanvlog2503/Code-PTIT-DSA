#include<bits/stdc++.h>

using namespace std;
int sz[100002], parent[100002];
int n, m;
void init(){
	for(int i = 1;i <= n;i++){
		parent[i] = i;
		sz[i] = 1;
	}
}
int find(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find(parent[u]);
}
bool uni(int a, int b){
	int x = find(a);
	int y = find(b);
	
	if(x == y) return false; // vi cung cha nen no da la 1 nhom
	
	if(sz[x] < sz[y]){
		parent[x] = y;
		sz[y] += sz[x];
	}else{
		parent[y] = x;
		sz[x] += sz[y];
	}
	return true;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		
		memset(parent, 0, sizeof(parent));
		memset(sz, 0, sizeof(sz));
		init();
		
		for(int i = 0;i < m;i++){
			int x, y;
			cin >> x >> y;
			uni(x, y);
		}
		
		int ans = 0;;
		for(int i = 1;i <= n;i++){
			if(ans < sz[i]){
				ans = sz[i];
			}
		}
		cout << ans << "\n";
		
	}
}