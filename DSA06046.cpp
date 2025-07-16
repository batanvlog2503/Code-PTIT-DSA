#include<iostream>
#include<algorithm>
using namespace std;

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
		
		int res = 1e9 + 6;
		
		sort(a, a + n);
		
		for(int i = 1;i <n;i++){
			if(a[i] - a[i - 1] < res){
				res = a[i] - a[i - 1];
			}
		}
		cout <<res<<endl;
	}
}