#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string SmallestNumber(int S, int D){
	int num = 9 * D;
	
	if(S > num){
		return "-1";
	}
	if(S == 0 && D > 1){
		return "-1";
	}
	
	S--;
	string result = "";
	vector<int> digit(D, 0);
	for(int i = D - 1;i > 0;i--){
		if(S > 9){
			digit[i] = 9;
			S-=9;
		}else{
			digit[i] = S;
			S = 0;
		}
	}
	
	digit[0] = S + 1;
	for(int x : digit){
		result += to_string(x);
	}
	return result;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int S, D;
		cin >> S >> D;
		
		cout << SmallestNumber(S, D) << endl;
	}
}