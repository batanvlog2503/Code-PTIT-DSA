#include<bits/stdc++.h>

using namespace std;

set<vector<int>> se;
void backtrack(int total, int start,vector<int> res, vector<vector<int>> &tmp ,int n){
	if(total == n){
		
		tmp.push_back(res);
		return ;
	}
	
	for(int i = start;i  >=  1;i--){
		int sum_cur = total + i;
		
		if(sum_cur <= n){
			res.push_back(i);
			backtrack(sum_cur,i, res, tmp, n);
			res.pop_back();
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		vector<int> res;
		vector<vector<int>> tmp;
		backtrack(0, n, res, tmp, n);
		cout << tmp.size() <<endl;
		for(vector<int> it : tmp){
			cout <<"(";
			for(int i = 0; i < it.size();i++){
				cout << it[i];
				if(i != it.size() - 1){
					cout <<" ";
				}
			}
			cout <<") " ;
		}
		se.clear();
		cout << endl;
	}
}