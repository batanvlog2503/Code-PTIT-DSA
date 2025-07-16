#include<iostream>

using namespace std;
bool check(int a[], int n){
	int l = 0, r = n -1;
	while(l < r){
		if(a[l] != a[r]){
			return false;
		}
		l++;
		r--;
	}
	return true;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a[n];
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		
		if(check(a, n)){
			cout << "YES";
		}else{
			cout <<"NO";
		}
		cout <<endl;
	}
}