#include<iostream>
#include<bits/stdc++.h>
// longest common substring

using namespace std;
int lcs(string s, string str){
	int n = s.length(), m = str.length();
	
	int dp[n + 1][m + 1];
	int res = 0;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else{
				if(s[i - 1] == str[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
					
				}else{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}
	return dp[n][m];
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string str;
		cin >> str;
		
		int n = str.length();
		
		string s = str;
		reverse(s.begin(), s.end());
		int x = lcs(s, str);
		cout << n - x << endl;
	}
}