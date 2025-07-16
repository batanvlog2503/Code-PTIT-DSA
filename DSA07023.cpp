#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string s;
		getline(cin, s);
		
		stringstream ss(s);
		string num;
		stack<string> st;
		while(ss >> num){
			st.push(num);
		}
		
		while(!st.empty()){
			cout << st.top()<<" ";
			st.pop();
		}
		cout << endl;
	}
}