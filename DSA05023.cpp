#include<bits/stdc++.h>

using namespace std;

void backtrack(int idx, string result, vector<char> &res, vector<vector<char>> & tmp){
	if(idx == result.length()){
		tmp.push_back(res);
		return;
	}
	res.push_back(result[idx]);
	backtrack(idx + 1, result, res, tmp);
	res.pop_back();
	backtrack(idx + 1, result, res,tmp);
	
}
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n;
		cin >> n;
		
		string result = to_string(n);
		long long ans = 0;
		for(int i = 0;i < result.length();i++){
			long long num = 0;
			for(int j = i;j < result.length();j++){
				
				num = num * 10 + result[j] - '0';
				ans += num;
			}
		
			
		}
		cout << ans << endl;
	}
}