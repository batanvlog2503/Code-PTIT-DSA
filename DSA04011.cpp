#include<bits/stdc++.h>

using namespace std;
long long binpow(long long a, long long n, long long c){
	long long res = 1;
	a %= c;
	
	while(n){
		if(n % 2 == 1){
			res *= a;
			res %= c;
		}	
		
		n/= 2;
		a*= a;
		a %= c;
	}
	return res;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n, k;
		cin >> n >> k;
	
		cout << binpow(n, k, 1e9 + 7) << endl;
	}
}