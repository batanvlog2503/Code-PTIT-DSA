#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int n;
int arr[1000][1000];
void backtrack(int idx, int &max_sum,int cur_sum, vector<bool> used){
	if(idx == n){
		max_sum = max(max_sum, cur_sum);
		return ;
	}
	for(int col = 0;col < n;col++){
		if(!used[col]){
			used[col] = true;
			backtrack(idx + 1, max_sum, cur_sum + arr[idx][col], used);
			used[col] = false;
		}
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		
		cin >> n;
		
	
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				cin >> arr[i][j];
			}
		}
		vector<bool> used(n + 1, false);
		int max_sum = 0;
		backtrack(0, max_sum,0, used);
		
		cout << max_sum << endl;
		
	}
}