#include<bits/stdc++.h>

using namespace std;
bool check(vector<string> &res, int col, int row){
	for(int i = 0;i < row;i++){
		if(res[i][col] == 'Q'){
			return false;
		}
	}
	for(int i = row - 1, j = col - 1;i >= 0 && j >= 0;i--, j--){
		if(res[i][j] == 'Q'){
			return false;
		}
	}
	for(int i = row - 1, j = col + 1;i >= 0 && j < 8;i--, j++){
		if(res[i][j] == 'Q'){
			return false;
		}
	}
	return true;
}

int a[9][9];
int total(vector<string> &res){
	int sum = 0;
	
	for(int i = 0;i < res.size();i++){
		for(int j = 0;j < res[0].size();j++){
			if(res[i][j] == 'Q'){
				sum += a[i][j];
				
			}
		}
	}
	
	return sum;
}


void backtrack(vector<vector<string>> &tmp, vector<string> &res, int row, int& ans){
	if(row == 8){
		tmp.push_back(res);
		int score = total(res);
			if(score > ans) {
   				 ans = score;
			
			}
		return ;
	}
	
	for(int col = 0;col < 8;col++){
		if(check(res, col, row)){
			res[row][col] = 'Q';
			backtrack(tmp, res, row + 1, ans);
			res[row][col] = '.';
		}
	}
}
int main(){

		int q;
		cin >> q;
		for(int o = 1;o <= q;o++){
			vector<string> res(8, string(8, '.'));
			int ans = -1e9 - 7;
			
			for(int i = 0;i < 8;i++){
				for(int j = 0; j < 8;j++){
					cin >> a[i][j];
				}
			}
		
			vector<vector<string>> tmp;
		
			backtrack(tmp, res, 0, ans);
		
//		for(vector<string> it : tmp){
//			for(auto i : it){
//				cout <<i<< endl;;
//			}
//			cout << endl;
//		}
			cout << "Test " << o <<": " << ans <<endl;
			ans = 0; 
			memset(a, 0, sizeof(a));
		}
	
}