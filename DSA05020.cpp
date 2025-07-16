#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
	int q;
	cin >> q;
	while(q--){
		int n, m;
		cin >> n >> m;
		
		int a[n][m];
		
		for(int i =0;i < n;i++){
			for(int j = 0;j <m;j++){
				cin >> a[i][j];
			}
		}
		int dp[n][m];
		dp[0][0] = a[0][0];
		for(int i = 1;i < m;i++){
			dp[0][i] = dp[0][i - 1] + a[0][i];
		}
		
		for(int j = 1;j < n;j++){
			dp[j][0] = dp[j - 1][0] + a[j][0];
		}
		
		for(int i = 1;i <n;i++){
			for(int j = 1;j < m;j++){
				dp[i][j] = a[i][j] + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
			}
		}
		cout << dp[n - 1][m - 1]<<endl;
	}
}

