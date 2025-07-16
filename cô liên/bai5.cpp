#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	string x;
	getline(cin, x);
	int q = x[0] - '0' + x[4] - '0';
	int p = x[8] - '0';
	if(p == q){
		cout <<"YES";
	}else{
		cout <<"NO";
	}
}