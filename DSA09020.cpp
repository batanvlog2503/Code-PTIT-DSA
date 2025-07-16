#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int a[1001][1001];
int main(){
	int n;
	cin >> n;
	cin.ignore();
	for(int i = 1;i <= n;i++){
		string str;
		getline(cin, str);
		stringstream ss(str);
		string num;
		while(ss >> num){
			a[i][stoi(num)] = 1;
		}
	}
	
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout <<  a[i][j] <<" ";
		}
		cout <<endl;
	}
}