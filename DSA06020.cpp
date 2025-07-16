#include<iostream>

using namespace std;
bool check(int a[], int l, int r, int k){
	int m = (l + r) / 2;
	
	while(l <= r){
		int m = (l + r) / 2;
		
		if(a[m] == k){
			return 1;
		}else if(a[m] > k){
			r = m - 1;
		}else{
			l = m + 1;
		}	
	}
	return 0;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		 cin >>n >> k;
		 
		 int a[n];
		 
		 for(int i = 0;i < n;i++){
		 	cin >> a[i];
		 }
		 
		 int l = 0, r = n - 1;
		 if(check(a, l, r, k)){
		 	cout << 1;
		 }else{
		 	cout << -1;
		 }
		 cout << endl;
		
	}
}