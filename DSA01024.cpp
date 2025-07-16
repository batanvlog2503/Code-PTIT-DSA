#include<bits/stdc++.h>

using namespace std;

bool check(string s){
	for(int i =0 ;i < s.length();i++){
		if(s[i] == ' '){
			return false;
		}
	}
	return true;
}
bool check1(vector<string> res){
	for(int i = 0;i < res.size() - 1;i++){
		if(res[i] == res[i + 1]){
			return false;
		}
	}
	return true;
}
void backtrack(int idx, int k,vector<string> &tmp, vector<string> &res, set<vector<string>> &v){
	if(res.size() == k){
		if(check1(res)){
			
			v.insert(res);
		}
		return ;
	}
	if (idx >= tmp.size()) return; 
	res.push_back(tmp[idx]);
	backtrack(idx + 1, k, tmp, res, v);
	res.pop_back();
	
	backtrack(idx + 1, k, tmp, res, v);
}
int main(){
	int n, k;
	cin >> n >> k;
	
	cin.ignore();
	vector<string> tmp;
	for(int i =0 ;i < n;i++){
		string x;
		cin >> x;
		if(check(x)){
			tmp.push_back(x);
		}
	}

	
	

	set<vector<string>> v;
	vector<string> res;
	
	sort(tmp.begin(), tmp.end());
	backtrack(0, k, tmp, res, v);
	
	for(vector<string> it : v){
		for(string x : it){
			cout <<x <<" ";
		}
		cout <<endl;
	}
	
	
}