#include<iostream>
#include<queue>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
vector<long long> res;
int n;
void init(){
	res.clear();
	queue<string> q;
	q.push("6");
	q.push("8");
	res.push_back(6);
	res.push_back(8);
	while(!q.empty()){
		string top = q.front();
		q.pop();
		if(top.length() >= n){
			break;
		}
		res.push_back(stoll(top + "6"));
		res.push_back(stoll(top + "8"));
		q.push(top + "6");
		q.push(top + "8");
	}
	
	
	cout << res.size()<<endl;
	for(int i = res.size() - 1;i >= 0;i--){
		cout << res[i] << " ";
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		
		cin >> n;
		init();
		cout <<endl;
	}
}