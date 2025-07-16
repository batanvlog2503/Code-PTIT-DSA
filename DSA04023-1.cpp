#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		
		int a[n];
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		
	
		sort(a, a + n);
		int count =0;
		for(int i = n - 1;i >=0 ;i--){
			for(int j = 0;j < i;j++){
				if(a[i] - a[j] < k){
					count += i - j;
					break;
				}
			}
		}
		cout << count << endl;
	}
}