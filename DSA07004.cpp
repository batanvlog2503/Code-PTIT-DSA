#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string s;
		cin >> s;
		
		int res = 0, balance = 0;
		for(char x : s){
			if(x == '('){
				balance++;
			}else{
				if(balance == 0){
					res++;
					balance++;
				}else{
					balance--;
				}
			}
		}
		res += balance/2;
		cout << res<<endl;
	}
}