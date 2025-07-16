#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[10004], ok ,n, k;
bool check(vector<int> res){
	for(int i = 1;i <res.size();i++){
		if(res[i - 1] >= res[i]){
			return false;
		}
	}
	return true;
}
void backtrack(int idx, int k, int a[], vector<int> &res, vector<vector<int>> &tmp){
	if(res.size() == k){
		if(check(res)){
			tmp.push_back(res);
			
			return;
		}
		
	}
	
	for(int i = idx;i < n;i++){
		res.push_back(a[i]);
		backtrack(i + 1, k, a, res, tmp);
		res.pop_back();
	}
}

int main(){
	
	cin >> n >> k;
	
	int a[n];
	
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	ok = 1;
	vector<vector<int>> tmp;
	vector<int> res;
	
	
	backtrack(0, k, a, res, tmp);
	cout << tmp.size();
	
}