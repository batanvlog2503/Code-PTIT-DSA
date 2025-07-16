#include<iostream>

using namespace std;
const int MOD = 1e9+7;
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n;
		cin >> n;
		long long dp[1005];
		dp[0] = dp[1] = 1;
		
		for(int i = 2;i <= n;i++){
			dp[i] = 0;
			
			for(int j = 0;j < i;j++){
				 dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % MOD) % MOD;
			}
		}
		cout <<dp[n]<<endl;
	}
}