#include<bits/stdc++.h>

using namespace std;
long long F[93];
char find(long long n, long long k){
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k <= F[n - 2]){
		return find(n - 2, k);
	}
	return find(n - 1, k - F[n - 2]);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n, k;
		cin >> n >> k;
		
	
	F[1] = 1;
		F[2] = 1;
		for(int i = 3;i <= 93;i++){
			F[i] =F[i - 2] +F[i - 1];
		}
		
		cout << find(n, k)<<endl;
		
	}
}