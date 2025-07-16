#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a[n];
		int b[n];
		for(int i = 0;i < n;i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a + n); sort(b, b + n, cmp);
		int l = 0, r = 0;
		int count = n;
		for(int i = 0;i < n;i++){
			if(i % 2 == 0){
				cout << b[l++];
			}else{
				cout << a[r++];
			}
			cout << " ";
		}
		cout <<endl;
	}
}
