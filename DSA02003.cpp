#include<bits/stdc++.h>


using namespace std;

int n;
int a[1002][1002];
vector<string> paths;
int dx[2] = {0, 1};
int dy[2] = {1, 0};

char c[2] = {'R', 'D'};
void dfs(int i, int j, string path){
	if(i == n && j == n){
		paths.push_back(path);
		return ;
	}
	int temp = a[i][j];
	a[i][j] = 0;
	for(int k = 0;k < 2;k++){
		int imoi = i + dx[k];
		int jmoi = j + dy[k];
		
		if(imoi >= 1 && jmoi >= 1 && jmoi <= n && imoi <= n && a[imoi][jmoi]== 1){
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
		dfs(1, 1, "");
		
		if(a[1][1] == 0 || a[n][n] == 0){
			cout << -1;
		}else{
			if(paths.empty()){
				cout << -1;
			}else{
				sort(paths.begin(), paths.end());
				paths.erase(unique(paths.begin(), paths.end()), paths.end());
				for(string s : paths){
					cout << s <<" ";
				}
			}
		}
		
		paths.clear();
		cout << endl;
	}
}