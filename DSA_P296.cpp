#include<bits/stdc++.h>

using namespace std;
int n;
const int MAXN = 1e5 + 5;
int a[MAXN];
long long prefix[MAXN];

void sum(int a[], int l, int r){
	
	for(int i = 1;i <= n;i++){
		prefix[i] = prefix[i - 1] + (a[i] >= 0 ? a[i] : 0);
	}
	
	long long sum_cur = prefix[r] - prefix[l - 1];
	if(sum_cur >= 0){
		cout << sum_cur;
	}else{
		int res = a[l];
		for(int i = l + 1;i <= r;i++){
			res = max(res, a[i]);
		}
		cout << res;
	}
	
	
}
int main(){
	int q;
	cin >> n >> q;


	
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		
		
	}
	
	while(q--){
		int l, r;
		cin >> l >> r;
		
		if(l == r){
			cout << 0;
		}else{
			int sum = 0;
			for(int i = l;i <= r;i++){
				if(a[i] >= 0){
					sum += a[i];
				}
			}
			cout << sum;
		}
		cout << endl;
		
	}
}