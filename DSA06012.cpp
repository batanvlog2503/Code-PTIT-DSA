#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		sort(a, a + n);
		for(int i = 0;i < k;i++){
			cout << a[n - i - 1] << " ";
		}
		cout << endl;
	}
}