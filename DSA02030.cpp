#include<iostream>
#include<vector>
using namespace std;
void backtrack(char idx,vector<vector<char>> &tmp, vector<char> &res, char x, int n){
	if(res.size() == n){
		tmp.push_back(res);
		return ;
	}
	
	for(char i = idx;i<=x;i++){
		res.push_back(i);
		backtrack(i, tmp, res, x, n);
		res.pop_back();
	}
}
int main(){
	char x;
	cin >> x;
	int n;
	cin >> n;
	
	vector<vector<char>> tmp;
	vector<char> res;
	
	backtrack('A',tmp, res, x, n);
	
	for(vector<char> it: tmp){
		for(char x : it){
			cout <<x ;
		}
		cout <<endl;
	}
}