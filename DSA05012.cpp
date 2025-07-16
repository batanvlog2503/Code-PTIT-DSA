#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MOD = 1e9 + 7;
long long a[1001][1001];
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n , k;
		cin >> n>> k;
		
		
		a[1][0] = a[1][1] = 1;
		for(int i = 2;i <= n;i++){
			for(int j = 0;j <= i;j++){
				if(j == 0 || j == i){
					a[i][j] = 1;
				}else{
					a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % MOD;
				}
			}
		}
		
		cout << a[n][k] << endl;
	}
}