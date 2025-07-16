#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void min1(string &str1){
	for(int i =0 ;i < str1.length();i++){
		if(str1[i] == '6'){
			str1[i] = '5';
		}
	}
}
void max1(string &str2){
	for(int i = 0;i < str2.length();i++){
		if(str2[i] == '5'){
			str2[i] = '6';
		}
	}
}
int main(){
	string str1, str2;
	cin >> str1 >> str2;
	min1(str1);
	min1(str2);
	cout << stoll(str1) + stoll(str2);
	max1(str1);
	max1(str2);
	cout<<" " << stoll(str1) + stoll(str2);
	
}