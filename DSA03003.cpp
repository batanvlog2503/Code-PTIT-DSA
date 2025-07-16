#include<iostream>
#include<algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n;
		cin >> n;
		
		long long a[n];
		long long sum = 0;
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		sort(a, a + n);
		for(int i =0 ;i < n;i++){
			sum = (sum + (a[i] * i) % MOD) % MOD;
		}
		cout << sum << endl;
	}
}