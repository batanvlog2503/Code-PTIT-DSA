#include<iostream>
#include<algorithm>
using namespace std;
int a[1000], b[1000], n, ok;
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
bool check(int a[], int b[]){
	for(int i = 1;i <= n;i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int count = 0;
		for(int i = 1;i <= n;i++){
			cin >> b[i];
		}
		khoitao();
		ok = 1;
		while(ok){
			if(check(a, b)){
				break;
			}
			sinh();
			count++;
		}
		cout << count + 1<<endl;
	}
}