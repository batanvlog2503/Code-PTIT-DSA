#include<bits/stdc++.h>

using namespace std;

int longeststr(string str){
	int n = str.length();
	int dp[n + 1][n + 1];
	
	for(int i = n - 1 ;i >= 0;i--){
		for(int j = i;j < n;j++){
			if(i == j){
				dp[i][j] = 1;
				continue;
			}
			if(str[i] == str[j]){
				if(i + 1 == j){
					dp[i][j] = 2;
				}else{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
			}else{
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][n - 1];
}
int main(){
	int q;
	cin >> q;
	
	cin.ignore();
	while(q--){
		string str;
		cin >> str;
		
		cout << str.length() - longeststr(str) << endl;
	}
}