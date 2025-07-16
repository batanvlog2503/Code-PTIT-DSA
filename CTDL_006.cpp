#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	set<int>  s;
	vector<int> v;
	for(int i =0 ;i < n;i++){
		int x;
		cin >> x;
		if(s.find(x) == s.end()){
			v.push_back(x);
		}
		s.insert(x);
	}
	for(int x : v){
		cout << x << " ";
	}
}