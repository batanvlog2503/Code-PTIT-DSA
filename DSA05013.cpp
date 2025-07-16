#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n, k;
		cin >> n >> k;
		
		vector<long long> ways(n + 1, 0);
		
		ways[0] = 1;
		
		for(long long i = 1;i <= n;i++ ){
			for(int j = 1;j <= min(i, k);j++){
				ways[i] = (ways[i] + ways[i - j]) % MOD;
			}
		}
		cout <<ways[n];
		cout <<endl;
	}
}