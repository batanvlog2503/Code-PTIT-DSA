#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void backtrack(int idx, vector<char> &arr, vector<char> &res, vector<string> &tmp){
	if(idx == arr.size()){
		if(!res.empty()){
			tmp.push_back(string(res.begin(), res.end()));
		}
		return;
	}
	
	res.push_back(arr[idx]);
	backtrack(idx + 1, arr, res, tmp);
	res.pop_back();
	backtrack(idx + 1, arr, res, tmp);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		cin.ignore();
		
		string str;
		
		cin >> str;
		
		vector<char> arr;
		for(int i =0 ;i < str.length();i++){
			arr.push_back(str[i]);
		}
		
		vector<string> tmp;
		vector<char> res;
		backtrack(0, arr, res, tmp);
		sort(tmp.begin(), tmp.end());
		for(int i = 0; i < tmp.size();i++){
			cout << tmp[i]<<" ";
		}
		cout <<endl;
	}
}