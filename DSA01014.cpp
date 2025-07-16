#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void backtrack(int idx, int total, int n, int k, int target, vector<int> &res, vector<vector<int>> &tmp){
	if(res.size() == k){
		if(total == target){
			tmp.push_back(res);
		}
		return;
		
	}
	

	
	for(int i = idx;i <= n;i++){
		int cur_sum = total + i;
		if(cur_sum <= target){
			res.push_back(i);
			backtrack(i + 1, cur_sum, n, k, target, res, tmp);
			res.pop_back();
		}else{
			return;
		}
	}
}
int main(){
	int n,k, s;
	while(1){
		cin >> n >> k >> s;
		if(n == 0 && k == 0 && s == 0){
			break;
		}else{
			vector<int> res;
			vector<vector<int>> tmp;
			
			backtrack(1, 0, n, k, s, res, tmp);
			cout << tmp.size() << endl;
		}
	}
}