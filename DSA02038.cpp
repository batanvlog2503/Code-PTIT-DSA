#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void backtrack(int idx,int k, vector<int> &arr, vector<int> &res, vector<vector<int>> &tmp){
	if(res.size() == k){
		tmp.push_back(res);
		return ;
	}
	
	for(int i = idx; i < arr.size();i++){
		res.push_back(arr[i]);
		backtrack(i + 1, k, arr, res, tmp);
		res.pop_back();
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >>n >> k;
		vector<int> arr(n);
		for(int i = 0;i < n;i++){
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		vector<int> res;
		vector<vector<int>> tmp;
		backtrack(0, k, arr, res, tmp);
		for(vector<int> it : tmp){
			for(int x : it){
				cout << x<<" ";
			}
			cout << endl;
		}
	}
}
//2 5 15
//2 5 10
//2 5 20
//5 10 20
//5 15 20
