#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int  a[n];
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
			
		}
		int count= 0;
		int min_idx = 1e9+7;
		
		for(int i = 0;i < n - 1;i++){
			int min_idx = i;
			for(int j = i + 1;j < n;j++){
				if(a[j] < a[min_idx]){
					min_idx = j;
				}
			}
			if(min_idx != i){
				swap(a[i], a[min_idx]);
				count++;
			}
		}
		cout << count << endl;
	}
}

