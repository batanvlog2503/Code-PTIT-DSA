#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> v(n), maxleft(n), minright(n);
		for(int i = 0;i < n;i++){
			cin >> v[i];
		}
		maxleft[0] = v[0];
		minright[n - 1] = v[n - 1];
		
		for(int i = 1;i < n;i++){
			maxleft[i] = max(maxleft[i - 1],v[i]);
		}
		for(int i = n - 2;i >= 0;i--){
			minright[i] = min(minright[i + 1], v[i]);
		}
		vector<int> res;
		for(int m = 1;m < n;m++){
			if(maxleft[m - 1] <= minright[m]){
				res.push_back(m);
			}
		}
		cout << res.size() <<endl;
		if(!res.empty()){
			for(int i = 0;i < res.size();i++){
				cout << res[i] <<" ";
			}
		}
		cout <<endl;
	}
}