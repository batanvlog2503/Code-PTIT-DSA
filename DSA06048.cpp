#include<bits/stdc++.h>

using namespace std;

int check(int a[], int n){
	
	for(int i = 1;i < n;i++){
		if(a[i - 1] >= a[i]){
			return i;
		}
	}
	return 0;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a[n], cnt = 0;
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		cout << check(a, n) << endl;
	}
}