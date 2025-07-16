#include<bits/stdc++.h>

using namespace std;

int V, E;
bool cmp(vector<int> a, vector<int> b){
	if(a[2] == b[2]){
		if(a[0] == b[0]){
			return a[1] < b[1];
		}
		return a[1] < b[1];
	}
	return a[2] < b[2];
}
int find(int u, vector<int>& parent){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find(parent[u], parent);
}
int main(){
	int q;
	cin >> q;
	
	while(q--){
		cin >> V >> E;
		
		vector<vector<int>> edge;
		for(int i =0;i < E;i++){
			int u, v, w;
			cin >> u >> v >> w;
			edge.push_back({u, v, w});
		}
		
		sort(edge.begin(), edge.end(), cmp);
		vector<int> parent(V + 1), rank(V + 1);
		for(int i = 1;i <= V;i++){
			parent[i] = i;
		}
		int min_weight = 0;
		int count = 0;
		for(auto ed : edge){
			int u = ed[0], v = ed[1], w = ed[2];
			
			int pu = find(u, parent);
			int pv = find(v, parent);
			
			if(pu != pv){
				
				if(rank[pu] < rank[pv]){
					swap(pu, pv);
				}
				parent[pv] = pu;
				if(rank[pu] == rank[pv]){
					rank[pu]++;
					
				}
				min_weight += w;
				count++;
				if(count == V-1){
					break;
				}
			}
		}
		 if (count < V-1) {
            cout << 0 << '\n';
        }
        else {
            cout << min_weight << '\n';
        }
    }
}