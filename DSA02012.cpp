#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, m;
		cin >> n >> m;
		int a[n][m];
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin >> a[i][j];
				a[i][j] = 1;
			}
		}
		int dp[n + 1][m + 1];
		
		for(int i = 0 ;i < n;i++){
			for(int j = 0;j < m;j++){
				if(i == 0 || j == 0){
					dp[i][j] = 1;
				}else{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		cout <<dp[n - 1][m - 1] <<endl;
	}
}