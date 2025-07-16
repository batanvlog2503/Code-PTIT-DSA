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
		
		for(int i = 0; i < n;i++){
			cin >> a[i];
		}
		int count = 0;
		for(int i = 0 ;i < n;i++){
			if(a[i] == k){
				count++;
			}
		}
		if(count == 0){
			cout << -1;
		}else{cout <<count;
		}
		cout << endl;
	}
}