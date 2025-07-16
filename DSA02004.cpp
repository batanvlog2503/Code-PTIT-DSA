#include<bits/stdc++.h>


using namespace std;
int n, m;
int a[1001][1001];
bool visited[1001];

vector<string> paths;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char c[4] = {'U', 'L', 'R', 'D'};
void dfs(int i, int j, string path){
	if(i == n && j == n){
		paths.push_back(path);
		return;
	}
	int temp = a[i][j];
	a[i][j] = 0;
	for(int k = 0;k < 4;k++){
		int imoi = i + dx[k];
		int jmoi = j + dy[k];
		
		if(imoi >= 1 && jmoi >= 1 && imoi <= n && jmoi <= n && a[imoi][jmoi] == 1){
			dfs(imoi, jmoi, path + c[k]);
		}
	}
	
	a[i][j] = temp;
	

}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cin >> a[i][j];
			}
		}
	
		memset(visited, false, sizeof(visited));
		dfs(1, 1, "");
		if(a[1][1] == 0 || a[n][n] == 0){
			cout << -1;
		}else{
			if(paths.empty()){
				cout << -1;
			}else{
				sort(paths.begin(), paths.end());
				paths.erase(unique(paths.begin(), paths.end()), paths.end());
				for(string x : paths){
					cout << x <<" ";
				
				}
			}
				
			
		}
		paths.clear();
		cout <<endl;
		
	}
}