#include<iostream>
#include<algorithm>

using namespace std;

char a[1000];
int n, k, ok;

void khoitao(){
	for(int i = 1;i <= k;i++){
		a[i] = '@' + i;
	}
}

void sinh(){
	int i = k;
	
	while(i >= 1 && a[i] == '@' + n - k + i){
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
	int q;
	cin >> q;
	while(q--){
		cin >> n >> k;
		khoitao();
		ok = 1;
		while(ok){
			for(int i = 1;i <= k;i++){
				cout <<  a[i];
			}
			sinh();
			cout << endl;
		}
	}
}