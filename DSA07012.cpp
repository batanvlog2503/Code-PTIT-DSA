#include<iostream>
#include<bits/stdc++.h>

using namespace std;
bool check(char c){
	if(c == '+' || c == '*' || c == '/' || c=='-'){
		return true;
	}
	return false;
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string str;
		cin >> str;
		
		
		stack<string> st;
		
		for(int i = 0;i < str.length();i++){
			char c = str[i];
			
			if(check(c)){
				string op1  = st.top();
				st.pop();
				string op2 = st.top();
				st.pop();
				
				string result = "(" + op2 + c + op1 + ")";
				st.push(result);
			}else{
				st.push(string(1, c));
			}
		}
		cout << st.top()<<endl;
	}
}