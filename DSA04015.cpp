#include<bits/stdc++.h>

using namespace std;
long long binary_search(long long a[], long long l, long long r, long long x){
	long long res = -1;
	while(l <= r){
		int m = (l + r) / 2;
		
		if(a[m] <= x){
			res = m;
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return res;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n, x;
		cin >>  n >> x;
		long long a[n];
		for(int i =0;i < n;i++){
			cin >> a[i];
		}
		sort(a, a + n);
		long long l = 0, r = n - 1;
		if(binary_search(a, l, r, x) == -1){
			cout << -1 << endl;
		}else{
			cout << binary_search(a, l, r, x) + 1<< endl;
			
		}
	}
}