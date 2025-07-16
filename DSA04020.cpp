#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		
		int a[n];
		for(int i =0 ;i < n;i++){
			cin >> a[i];
		}
		
		int l = 0, r = n  - 1;
		bool check = false;
		while(l <= r){
			int m = (l + r) / 2;
			
			if(a[m] == k){
				cout << m + 1;
				check = true;
				break;
			}else if(a[m] > k){
				r = m - 1;
			}else{
				l = m + 1;
			}
		}
		if(check == false){
			cout << "NO";
		}
		cout << endl;
	}
}
