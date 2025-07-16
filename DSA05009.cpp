#include<bits/stdc++.h>

using namespace std;

void backtrack(int idx, vector<int> v, vector<int> &res, vector<vector<int>> &tmp){
	if(idx == v.size()){
		if(!res.empty()){
			tmp.push_back(res);
		
		}
		return ;
	}
	
	res.push_back(v[idx]);
	backtrack(idx  + 1, v, res, tmp);
	res.pop_back();
	backtrack(idx + 1,v, res, tmp);
}

int sum_cur(vector<int> it){
	int sum = 0;
	for(int i = 0;i < it.size();i++){
		sum += it[i];
	}
	return sum;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		vector<int> v(n);
		int sum = 0;
		for(int i = 0;i < n;i++){
			cin >> v[i];
			sum += v[i];
		}
		
		vector<int> res;
		vector<vector<int>> tmp;
		
		backtrack(0,v, res, tmp);
		set<int> se;
		set<vector<int>> s;
		bool check = false;
		for(vector<int> it : tmp){
			int target = sum_cur(it);
			int x = sum - target;
			if(se.find(x) != se.end() && s.find(it) != s.end()){
				check = true;
				break;
			}
			se.insert(target);
			s.insert(it);
		}
		for(vector<int> it:tmp){
			for(int i : it){
				cout << i << " ";
			}
			cout << endl;
		}
		cout <<endl;
	}
}