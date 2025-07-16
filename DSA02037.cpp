#include<iostream>
#include<bits/stdc++.h>

using namespace std;
bool snt(int n){
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0){
			return false;
		}
	}
	return n > 1;
}
bool check1(vector<int> res){
	long long sum = 0;
	for(int i = 0;i < res.size();i++){
		sum += res[i];
	}
	if(snt(sum)){
		return true;
	}
	return false;
}
bool check2(vector<int> res){
	if(res.size() == 1){
		return true;
	}
	for(int i = 1;i < res.size();i++){
		if(res[i - 1] >= res[i]){
			return false;
		}
	}
	return true;
}
void backtrack(int idx, vector<int> &arr,vector<int> &res, vector<vector<int>> &tmp){
	if(idx == arr.size()){
		if(check1(res) && check2(res)){
			tmp.push_back(res);
		}
		return ;
	}
	
	res.push_back(arr[idx]);
	backtrack(idx + 1, arr,res, tmp);
	res.pop_back();
	backtrack(idx + 1, arr,res, tmp);
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
		sort(arr.begin(), arr.end(), greater<int>());
		vector<int> res;
		vector<vector<int>> tmp;
		backtrack(0, arr, res, tmp);
		vector<string> s;
		
		for(vector<int> it : tmp){
			for(int i = 0;i < it.size();i++){
				cout << it[i] << " ";
			}
			cout <<endl;
		}
	}
}