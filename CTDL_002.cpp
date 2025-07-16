#include<iostream>

using namespace std;
int a[1000], b[1000], ok, n, k;

void khoitao(){
	for(int i = 0;i < n;i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n - 1;
	while(i >= 0 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i < 0){
		ok = 0;
	}else{
		a[i] = 1;
	}
}

bool check(int a[], int b[]){
	int sum = 0;
	for(int i = 0; i < n;i++){
		sum += a[i] * b[i];
	}
	
	if(sum == k){
		return true;
	}
	return false;
}
int main(){
	cin >> n >> k;
	
	for(int i = 0;i < n;i++){
		cin >> b[i];
	}
	
	ok = 1;
	khoitao();
	int count = 0;
	while(ok){
		if(check(a, b)){
			for(int i = 0; i < n;i++){
				if(a[i] != 0){
					cout<<b[i]<<" ";
				}
			}
			cout<<endl;
			count++;
		}
		sinh();
	}
	cout<<count;
}