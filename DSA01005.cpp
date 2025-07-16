#include<iostream>
#include<algorithm>
using namespace std;

int a[1000], n, ok;

void khoitao(){
	for(int i = 1;i <= n;i++){
		a[i] = i;
	}
}

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
		khoitao();
		
		ok = 1;
		while(ok){
			for(int i = 1;i <= n;i++){
				cout << a[i];
			}
			sinh();
			cout<<" ";
		}
		cout << endl;
	}
}