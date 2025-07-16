#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int a[n];
	
	for(int i = 0;i <n;i++){
		cin >> a[i];
	}
	
	vector<int> dp(n + 1,1);
	int res = 1;
	for(int i = 1;i < n;i++){
		for(int j =0 ;j < i;j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(res, dp[i]);
			}
		}
	}
	cout <<res;
	
}