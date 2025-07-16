#include<bits/stdc++.h>

using namespace std;

bool nt(int n){
	for(int i = 2;i * i <= n;i++){
		if(n % i == 0){
			return false;
		}
		
	}
	return n > 1;
}

void backtrack(int n, int idx, int target, int total, vector<int>& res,vector<vector<int>>& tmp){
	if(res.size() == n){
		if(target == total){
			tmp.push_back(res);
		}
		return;
	}
	
	for(int i = idx;i <= target;i++){
		if(nt(i)){
			int sum_cur = total + i;
			if(sum_cur <= target){
				res.push_back(i);
				backtrack(n, i + 1, target, sum_cur, res, tmp);
				res.pop_back();
			}else{
				return;
			}
		}	
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, p, target;
		cin >> n >> p >> target;
		vector<int> res;
		vector<vector<int>> tmp;
		backtrack(n, p + 1, target, 0, res, tmp);
		cout << tmp.size() << endl;
		for(vector<int> it: tmp){
			for(int i : it){
				cout << i << " ";
			}
			cout << endl;
		}
	}
}