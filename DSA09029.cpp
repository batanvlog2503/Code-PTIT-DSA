#include<bits/stdc++.h>
using namespace std;

int a[1001][1001];
bool visited[1001];
int n, m;
vector<int> adj[1001];
bool found;

void find_haminlton(int u, int count){
	if(count == n){ // đã đi hết số điểm
		found = true;
		return;
	}
	visited[u] = true;
	
	for(int x : adj[u]){
		if(!visited[x]){
			find_haminlton(x, count + 1);
		}
	}
	visited[u] = false; // trả về false;
	
	
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n >> m;
		memset(visited, false, sizeof(visited));
		memset(a, 0, sizeof(a));
		memset(adj, {}, sizeof(adj));
		for(int i = 0;i < m;i++){
			int x,y;
			cin >> x >> y;
			
			adj[x].push_back(y);
			adj[y].push_back(x);
			
		}
		found = false;
		for(int i = 1;i <= n;i++){
			memset(visited, false, sizeof(false));
		
			bool found = false;
			find_haminlton(i, 1);
			
			if(found){
				break;
			}
		}
		if(found == false){
			cout << "0";
		}else{
			cout << "1";
		}
		cout << endl;
		
		
	}
}
