#include<bits/stdc++.h>

using namespace std;

bool check1(string str){
	for(int i = 1;i < str.length();i++){
		if(str[i - 1] > str[i]){
			return false;
		}
	}
	return true;
}
bool check2(string str){
	for(int i = 1;i < str.length();i++){
		if(str[i - 1] < str[i]){
			return false;
		}
	}
	return true;
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string str;
		cin >> str;
		if(check1(str) || check2(str)){
			cout <<"YES";
		}else{
			cout <<"NO";
		}
		cout << endl;
	}
}