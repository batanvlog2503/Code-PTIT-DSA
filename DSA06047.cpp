#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		long long n;
		cin >> n;
		vector<long long> v(n);
		
		for(int i = 0;i < n;i++){
			cin >> v[i];
			v[i] = v[i] * v[i];
		}
		sort(v.begin(), v.end());
		bool check = false;
		for(int i = n - 1;i >= 0;i--){
			
			int j = 0, k = i - 1;
			long long res = v[i];
			
			while(j < k){
				long long total = v[j] + v[k];
				
				if(total == res){
					check = true;
					break;
				}else if(total > res){
					k--;
				}else{
					j++;
				}
			}
		}
		if(check == true){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout <<endl;
	}
}