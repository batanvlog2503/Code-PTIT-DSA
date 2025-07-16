#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		string str = "";
		for(int i = 0;i < n;i++){
			str += to_string(a[i]);
		}
		
		set<char> s;
		for(int i = 0;i < str.length();i++){
			s.insert(str[i]);
		}
		for(auto x : s){
			cout << x << " ";
		}
		cout << endl;
	}
}