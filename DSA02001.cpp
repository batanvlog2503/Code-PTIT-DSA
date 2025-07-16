#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void backtrack(int n, vector<int> &arr, vector<vector<int>> &tmp){
	if(n < 1){
		return;
	}
	vector<int> res(n - 1);
	for(int i = 0;i < n - 1;i++){
		res[i] = arr[i] + arr[i + 1];
		
	}
	
	tmp.push_back(res);
	backtrack(n - 1, res, tmp);
	
	
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> arr(n);
		
		for(int i = 0;i < n;i++){
			cin >> arr[i];
		}
		vector<int> res;
		vector<vector<int>> tmp;
		tmp.push_back(arr);
		backtrack(n, arr,  tmp);
		for(vector<int> it: tmp){
			
			if(!it.empty()){
				cout <<"[";
				for(int i= 0;i < it.size();i++){
				cout << it[i];
				if(i != it.size() - 1){
					cout <<" ";
				}
			}
			cout <<"]";
			cout <<endl;
			}
		}
	}
}