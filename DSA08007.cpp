#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std ;
vector<long long> res;
long long n;

void init(){
	
	int count =0 ;
	
	queue<long long> q;
	
	q.push(1);
	
	while(!q.empty()){
		long long num  = q.front();
		q.pop();
		
		if(num > n){
			break;
		}	
		count++;
		long long op1 = num * 10;
		long long op2 = num * 10 + 1;
		if(op1 <= n){
			q.push(op1);
		}
		if(op2 <= n){
			q.push(op2);
		}
	}
	cout << count << endl;
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