#include<bits/stdc++.h>

using namespace std;
int n, m;


int max_square(int a[][501],vector<vector<int>> &dp, int n, int m){
	
	int maxi = 0;
	for(int i = n - 1;i >= 0;i--){
		for(int j = m - 1;j >= 0;j--){
			int right = dp[i][j + 1];
			int right_down = dp[i + 1][j + 1];
			int down = dp[i + 1][j];
			if(a[i][j] == 1){
				int ans = 1 + min({right, right_down, down});
				maxi = max(maxi, ans);
				dp[i][j] = ans;
			}
		}
	}
	return maxi;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		
		cin >> n >> m;
		int a[501][501];
	
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin >> a[i][j];
			}
		}
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		
		cout << max_square(a, dp,n, m) << endl;;
	}
}