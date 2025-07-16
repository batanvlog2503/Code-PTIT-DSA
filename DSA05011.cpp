#include<bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
bool check(vector<int> &it){
	int ok = -1;
	for(int i = 0;i < it.size();i++){
		if(it[i] == 0){
			ok = 1;
			break;
		}
		if(it[i] !=0){
			ok = 2;
			break;
		}
	}
	if(ok == 1) return false;
	return true;
}
void backtrack(int n, int target, int total, vector<int> &res, vector<vector<int>> &tmp){
	if(res.size() == n){
		if(total == target){
			if(check(res)){
				tmp.push_back(res);
			}
			
		}
		return;
	}
	for(int i = 0 ;i <= 9;i++){
		int sum_cur = i + total;
		if(sum_cur <= target){
			res.push_back(i);
			backtrack(n, target, sum_cur, res, tmp);
			res.pop_back();
		}else{
			return ;
		}
	}
}

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, target ;
		cin >> n >> target;
		vector<int> res;
		vector<vector<int>> tmp;
		
		backtrack(n, target, 0, res, tmp);
		
		cout << tmp.size() % MOD << endl;
	}
}