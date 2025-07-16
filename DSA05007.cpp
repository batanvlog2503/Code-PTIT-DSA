#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		long long n;
		cin >> n;
		vector<long long> arr(n);
		
		vector<long long> dp(n + 1, 0);
		for(int i = 0;i < n;i++){
			cin >> arr[i];
		}
		dp[0] = arr[0];
		dp[1] = max(arr[0], arr[1]);
		for(int i = 2;i < n;i++){
			dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
		}
		cout << max(dp[n - 1], dp[n - 2]);
		cout << endl;
	}
}