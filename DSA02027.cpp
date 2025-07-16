#include<bits/stdc++.h>

using namespace std;

int a[1001][1001];
bool visited[1001];


vector<vector<int>> paths;
int n;

int sum_vec(vector<int> v){
	int sum = 0;
	if(v.size() < 2){
		return 0;
	}
	for(int i = 0;i < v.size() - 1;i++){
		sum += a[v[i]][v[i + 1]];
	}
	return sum;
}
void cycle_hamilton(int u, int start, vector<int>& path){
	
	if(path.size() == n){
		if(a[path.back()][path[0]] != 0){ // nếu có đường đi về cuối
			path.push_back(start);
			paths.push_back(path);
		}
		return ;
	}
	for(int i = 1;i <=n ;i++){
		if(!visited[i] && a[u][i] > 0){
			visited[i] = true;
			path.push_back(i);
			cycle_hamilton(i, start, path);
			path.pop_back();
			visited[i] = false;
		}
	}
}
int main(){
	cin >> n ;
	if(n > 15){
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	int start = 1;
	vector<int> path;
	path.push_back(1);
	visited[1] = true;
	cycle_hamilton(1, start, path);
	
	int res = 1e9 + 7;
	vector<int> tmp;
	if(paths.empty()){
		return 0;
	}
	if(!paths.empty()){
		for(vector<int> path:paths){
			if(!path.empty()){
				if(sum_vec(path) < res){
					res = sum_vec(path);
					tmp = path;
				}
			}
		}
	}
	cout << res;
}