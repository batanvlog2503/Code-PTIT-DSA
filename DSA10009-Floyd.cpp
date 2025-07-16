#include<bits/stdc++.h>

using namespace std;
const int INF = 10000;

int main(){
	int V, E;
	cin >> V >> E;
	vector<vector<int>> graph(V + 1, vector<int>(V + 1, 1e9));
	for(int i = 1;i <= V;i++){
		graph[i][i] = 0;
	}
	vector<vector<int>> next(V + 1, vector<int>(V + 1, -1));
	for(int i  = 1;i <= E;i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = w;
		graph[v][u] = w;
		next[u][v] = v;
	}
	
	
	for(int k = 1;k <= V;k++){
		for(int i = 1;i <= V;i++){
			for(int j = 1;j <= V;j++){
				if(graph[i][k] < 1e9 && graph[k][j] <1e9 && graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
	
	int q;
	cin >> q;
	while(q--){
		int s, t;
		cin >> s >> t;
	
		cout << graph[s][t] << endl;
		vector<int> path;
		int current = s;
		while(current != t){
			if(current == -1) break;
			path.push_back(current);
			current = next[current][t];
		}
		//path.push_back(t);
		for(int x : path){
		//	cout << x << " ";
		}
	}

}


