#include<iostream>
#include<algorithm>
using namespace std;

int a[1000], ok , n;

void sinh(){
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]){
		i--;
	}
	
	if(i == 0){
		ok = 0;
	}else{
		int j = n;
		while(a[i] > a[j]){
			j--;
		}
		swap(a[i], a[j]);
		int l = i + 1, r = n;
		reverse(a + l, a + r + 1);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		ok = 1;
		sinh();
		if(ok){
			for(int i = 1;i <= n;i++){
				cout << a[i] << " ";
			}
		}else{
			for(int i = 1;i <= n;i++){
				cout << i<<" ";
			}
		}
		cout<<endl;
	}
}