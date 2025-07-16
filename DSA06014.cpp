#include<iostream>

using namespace std;
int check(int n){
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0){
			return 0;
		}
	}
	return n > 1;
}
int main(){
	int q;
	cin >> q;
	
	while(q--){
		int n;
		cin >> n;
		bool res = false;
		for(int i = 2;i < n;i++){
			if(check(i) && check(n - i)){
				cout << i << " " << n - i;
				res = true;
				break;
			}
		}
		if(res ==false){
			cout<<-1;
		}
		cout <<endl;
	}
}