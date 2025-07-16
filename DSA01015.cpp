#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std ;
vector<long long> res;
long long n;

void init(){
	
	int count =0 ;
	
	queue<long long> q;
	
	q.push(9);
	
	while(!q.empty()){
		long long num = q.front();
		
		if(num % n == 0){
			cout << num;
			break;
		}
		q.pop();
		long long num1 = num * 10;
		long long num2 = num * 10 + 9;
		if(num1 % n == 0){
			cout << num1;
			break;
		}
		if(num2 % n == 0){
			cout << num2 ;
			break;
		}
		q.push(num1);
		q.push(num2);
	}
	cout << endl;
	
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		
		cin >> n;
		
		init();
		
	}
}