#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void backtrack(int idx, int total, int k, vector<int> &arr, vector<vector<int>> &tmp, vector<int> &res){
	if(total == k){
		tmp.push_back(res);
		return ;
	}
	
	for(int i = idx;i < arr.size();i++){
		int cur_sum = total + arr[i];
		if(cur_sum <= k){
			res.push_back(arr[i]);
			backtrack(i, cur_sum, k, arr, tmp, res);
			res.pop_back();
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		
		vector<int> arr(n);
		
		for(int i = 0;i < n;i++){
			cin >> arr[i];
		}
		vector<vector<int>> tmp;
		vector<int> res;
		backtrack(0, 0, k, arr, tmp, res);
		
		if(tmp.empty()){
			cout << -1;
		}else{
			cout << tmp.size()<<" ";
			for(vector<int> it : tmp){
				cout <<"{";
				for(int i = 0;i < it.size();i++){
					cout << it[i];
					if(i != it.size() - 1){
						cout <<" ";
					}
				}
				cout<<"} ";
			}
		}
		cout << endl;
	}
}
