#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, S;
		cin >>n >> S;
		int a[n];
		for(int i =0 ;i < n;i++){
			cin >> a[i];
		}
		
		vector<bool> dp(S + 1, false);
		dp[0] = true;
		// co s? dp[j - a[i]] = true;
		for(int i = 0 ;i < n;i++){
			for(int j = S;j >= a[i];j--){
				if(dp[j - a[i]] == true){
					dp[j] = true; 
				}
			}
		}
		if(dp[S] == true){
			cout << "YES";
		}else{
			cout <<"NO";
		}
		cout <<endl;
	}
}