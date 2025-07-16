#include<bits/stdc++.h>

using namespace std;


char a[1001][1001];
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int i, int j){
	a[i][j] = '.';
	
	for(int k = 0;k < 4;k++){
		int imoi = i + dx[k];
		int jmoi = j + dy[k];
		
		if(imoi >= 0 && jmoi >= 0 && imoi < n && jmoi < m && a[imoi][jmoi] == '#'){
			dfs(imoi, jmoi);
		}
	}	
}
int main(){
	cin >> n >> m;
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> a[i][j];
		}
	}
	int count = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(a[i][j] == '#'){
				count++;
				dfs(i, j);
			}
		}
	}
	cout << count;
}