
#include<bits/stdc++.h>

using namespace std;

int n, a[10000], ok;

bool check(){
	int sum = 0;
	for(int i = 1;i < n;i++){
		sum += a[i] - a[i + 1];
	}
	if(sum > 0){
		return true;
	}
	return false;
}
void khoitao(){
	for(int i = 1;i <= n;i++){
		a[i] = i;
	}
}

void sinh(){
	int i = n - 1;
	while(i > 0 && a[i] > a[i + 1]){
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
	
	cin >> n;
	
	ok = 1;
	khoitao();
	while(ok){
		if(check()){
			for(int i = 1;i <= n;i++){
				cout << a[i] << " ";
			}
			cout << endl;
		
		}
		sinh();
	}
	
}