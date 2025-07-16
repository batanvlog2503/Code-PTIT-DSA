#include<iostream>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a[n];
		int count = 0;
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		for(int i = 0;i < n;i++){
			if(a[i] == 0){
				count++;
			}
		}
		cout << count<<endl;
	}
}