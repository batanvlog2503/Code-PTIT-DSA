#include<iostream>

using namespace std;
int n, k, a[1000], ok;

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i){
		i--;
	}
	
	if(i == 0){
		ok = 0;
	}else{
		a[i]++;
		for(int j = i + 1;j <= k;j++){
			a[j] = a[j - 1] + 1;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		ok = 1;
		for(int i = 1;i <= k;i++){
			cin >> a[i];
		}
		sinh();
		if(ok){
			for(int i = 1 ;i <= k;i++){
				cout << a[i]<<" ";
			}
		}else{
			for(int i = 1;i <= k;i++){
				cout << i << " ";
			}
		}
		cout<<endl;
	}
}