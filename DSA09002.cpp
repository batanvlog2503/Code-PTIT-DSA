#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> adj;
	cin.ignore();
	for(int i =0 ;i < n;i++){
		string str;
		
		getline(cin, str);
		
		stringstream ss(str);
		string num;
		
		while(ss >> num){
			if(stoi(num) > i + 1){
				adj.push_back({i + 1, stoi(num)});
			}
		}
		
	}
	for(auto x : adj){
			cout << x.first <<" "<<x.second<<endl;
		}
}
