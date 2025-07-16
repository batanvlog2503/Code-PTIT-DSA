#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, m, k;
		cin >> n >> m >> k;
		cin.ignore();
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
		
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				for(int q = 1;q <= k;q++){
					if(s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[q - 1] && s2[j - 1] == s3[q - 1]){
						dp[i][j][q] = 1 + dp[i - 1][j - 1][q - 1];
					}else{
						dp[i][j][q] = max({dp[i - 1][j][q], dp[i][j - 1][q], dp[i][j][q - 1]});
					}
				}
			}
		}
		cout << dp[n][m][k] << endl;
	}
}