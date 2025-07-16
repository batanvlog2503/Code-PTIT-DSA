#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		long long a[n];
		
		for(int i =0 ;i < n;i++){
			cin >> a[i];
		}
		long long dp[n + 1];
		
		dp[0] = a[0];
		dp[1] = max(a[0], a[1]);
		for(int i = 2;i < n;i++){
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		}
		cout << max(dp[n - 1], dp[n - 2])<<endl;
	}
}