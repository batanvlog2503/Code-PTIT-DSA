#include<iostream>
#include<algorithm>
#include<set>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		long long n1, n2, n3;
		
		cin >> n1 >> n2 >> n3;
		
		vector<long long> a(n1), b(n2), c(n3);
		
		map<long long, long long> mp;
		for(int i = 0;i < n1;i++){
			cin >> a[i];
			
		}
		for(int i =0;i < n2;i++){
			cin >> b[i];
		}
		for(int i = 0;i < n3;i++){
			cin >> c[i];
		}
		
	
		bool check = false;
		int i = 0, j = 0, k = 0;
		vector<long long> res;
		
		while(i < n1 && j < n2 && k < n3){
			if(a[i] == b[j] && b[j] == c[k]){
				if(res.empty() || res.back() != a[i]){
					res.push_back(a[i]);
				}
				i++;j++;k++;
			}else if(a[i] < b[j]){
				i++;
			}else if(b[j] < c[k]){
				j++;
			}else{
				k++;
			}
		}
		if(res.empty()){
			cout << "-1";
		}else{
			for(int o =0; o< res.size();o++){
				cout << res[o] << " ";
			}
			
		}
		cout <<endl;
	}
}