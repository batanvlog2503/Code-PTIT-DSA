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
		
		int res = 1e9 + 7;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				int x = a[i] + a[j];
				if(abs(x) < abs(res)){
					res = x;
				}
			}
		}
		cout <<res << endl;
	}
}