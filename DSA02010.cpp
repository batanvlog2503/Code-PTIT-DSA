#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void backtrack(int idx,int total, int k, vector<int> &arr, vector<int> &res, vector<vector<int>> &tmp){
	if(total == k){
		tmp.push_back(res);
		return ;
	}
	if(idx >= arr.size() || total > k){
		return ;
	}
	res.push_back(arr[idx]);
	backtrack(idx, total + arr[idx], k, arr, res, tmp);
	res.pop_back();
	backtrack(idx + 1, total, k, arr, res, tmp);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, x;
		cin >> n >> x;
		
		vector<int> arr(n);
		vector<int> res;
		vector<vector<int>> tmp;
		
		for(int i = 0;i < n;i++){
			cin >> arr[i];
		}
		
		backtrack(0, 0, x, arr, res, tmp);
		
		if(tmp.empty()){
			cout << -1;
		}else{
			for(vector<int> it : tmp){
				if(!it.empty()){
					cout <<"[";
					for(int i = 0;i < it.size();i++){
						cout << it[i];
						if(i != it.size() - 1){
							cout << " ";
						}
					}
					cout <<"]";
					
				}
			}
		}
		cout <<endl;
	}
}