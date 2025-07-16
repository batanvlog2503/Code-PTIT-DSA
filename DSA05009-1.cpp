#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[1000],n, ok;



int main(){
	int q;
	cin >> q;
	
	while(q--){
		cin >> n;
		vector<int> b(n);
		int sum = 0;
		for(int i = 0;i < n;i++){
			cin >> b[i];
			sum += b[i];
		}
		if(sum % 2 == 1){
			cout <<"NO";
		}else{
			int target = sum / 2;
			
			vector<bool> dp(target + 1, false);
			dp[0] = true;
			
			for(int i = 0;i < n;i++){
				for(int j = target;j >= b[i];j--){
					if(dp[j - b[i]] == true){
						dp[j] = true;
					}
				}
			}
			if(dp[target] == true){
				cout <<"YES";
			}else{
				cout <<"NO";
			}
		}
		cout << endl;
	}
	
}