#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		vector<int> v(n);
		
		for(int i = 0;i < n;i++){
			cin >> v[i];
		}
		vector<int> left_min(n), right_max(n);
		left_min[0] = v[0];
		
		for(int i = 1;i < n;i++){
			left_min[i] = min(v[i], left_min[i - 1]);
		}
		
		right_max[n - 1] = v[n - 1];
		
		for(int i = n - 2;i >= 0;i--){
			right_max[i] = max(v[i], right_max[i + 1]);
		}
		
		int i = 0, j = 0;
		int ans = -1;// cập nhât;
		while(i < n && j < n){
			if(left_min[i] < right_max[j]){
				ans = max(ans, j - i);
				j++;
			}else{
				i++;
			}
		}
		cout << ans <<endl;
		
	}
}