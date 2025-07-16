#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string str;
		cin >> str;
		
		int n = str.length();
		vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
		for(int i = 0;i < n;i++){
			dp[i][i] = true;
		}
		int max_length = 1;
		int start = 0;
		
		for(int i = 0;i < n - 1;i++){
			if(str[i] == str[i + 1]){
				dp[i][i + 1] = true;
				start = i;
				max_length= 2;
			}
		}
		for(int gap = 2;gap <= n;gap++){
			for(int i = 0;i< n - gap + 1;i++){
				int j = i + gap - 1;
				if(str[i] == str[j]){
					if(dp[i + 1][j - 1]){
						dp[i][j] = true;
						start  = i;
						max_length = max(max_length, gap);
					}
				}
			}
		}
		cout << max_length <<endl;
		
	}
}