#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i = 0;i < n;i++){
		int x, y;
		cin >> x >> y;
		mp[x] = y;
	}
	for(auto x : mp){
		cout << x.first << " " << x.second << endl;
	}
}
