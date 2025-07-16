#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second != b.second){
		return a.second > b.second;
	}
	return a.first < b.first;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a[n];
		unordered_map<int, int> mp;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		
		vector<pair<int, int>> v(mp.begin(), mp.end());
		sort(v.begin(), v.end(), cmp);
		
		for(auto x : v){
			for(int i = 0;i < x.second;i++){
				cout << x.first <<" ";
			}
		}
		cout << endl;
	}
}