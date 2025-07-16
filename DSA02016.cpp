#include<bits/stdc++.h>


using namespace std;

bool check(vector<string> &res, int row, int col, int n){
	for(int i = 0;i < n;i++){
		if(res[i][col] == 'Q'){
			return false;
		}
	}
	for(int i = row - 1, j = col + 1;i >= 0 && j < n;i--,j++){
		if(res[i][j] == 'Q'){
			return false;
		}
	}
	for(int i = row - 1, j = col - 1;i >= 0 && j >= 0;i--,j--){
		if(res[i][j] == 'Q'){
			return false;
		}
	}
	return true;
}
void backtrack(vector<string> &res, vector<vector<string>>& tmp, int n, int row){
	if(row == n){
		tmp.push_back(res);
		return ;
	}
	
	for(int col = 0;col < n;col++){
		if(check(res, row, col, n)){
			res[row][col] = 'Q';
			backtrack(res, tmp, n, row + 1);
			res[row][col] = '.';
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<string> res(n , string(n, '.'));
		vector<vector<string>> tmp;
		
		backtrack(res, tmp, n, 0);
		
		cout << tmp.size() << endl;
	}
}