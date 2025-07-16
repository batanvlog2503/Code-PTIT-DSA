#include<bits/stdc++.h>

using namespace std;
int n;
int sum(vector<int> v){
	int sum = 0;
	for(int i = 0;i < v.size();i++){
		sum += v[i];
	}
	return sum;
}
bool used[1001];
void backtrack(int idx, int total, vector<int> &res, vector<vector<int>> &tmp, vector<int> &v, int target){
	if(total == target){
		if(res.size() < n){
			tmp.push_back(res);
			
		}
		return ;
	}
	if(idx >= v.size() || total > target){
		return ;
	}
	
	for(int i = idx;i < v.size();i++){
		int cur_sum = total + v[i];
		if(cur_sum <= target){
			
			res.push_back(v[i]);
			backtrack(i + 1, cur_sum, res, tmp, v, target);
			res.pop_back();
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int  k;
		cin >> n >> k;
		
		vector<int> v;
		for(int i = 0;i < n;i++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		int target = sum(v);
		memset(used, false,sizeof(used));
		if(target % k == 0){
			vector<vector<int>> tmp;
			vector<int> res;
			backtrack(0, 0, res, tmp, v, target / k);
			cout << tmp.size() << endl;
			for(vector<int> it :  tmp){
				for(int x : it){
					cout << x <<" ";
					
				}
				cout << endl;
			}
			if(k == 1){
				cout << 1;
			}else if(tmp.size() == k){
				cout << 1;
			}
		}else{
			cout << 0;
		}
		cout << endl;
	}
}