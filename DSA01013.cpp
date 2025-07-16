#include<bits/stdc++.h>

using namespace std;
string convert(int num, int n){
	string res = "";
	while(num){
		int r = num % 2;
		res += to_string(r);
		num /= 2;
	}
	while(res.length() < n){
		res += '0';
	}
	reverse(res.begin(), res.end());
	return res;
}
string convert1(string gray){
	string binary = "";
	
	binary += gray[0];
	
	for(int i = 1;i < gray.length();i++){
		char prev = binary[i - 1];
		char cur = gray[i];
		// xor với nhau là ra gray giữa B i - 1 và g i
		if(cur == prev){
			binary += '0';
		}else{
			binary += '1';
		}
	}
	return binary;
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string str;
		cin >> str;
		
		cout << convert1(str) << endl;
		
	}
	
}