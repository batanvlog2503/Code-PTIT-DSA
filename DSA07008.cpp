#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pre(char c){
	if(c == '^'){
		return 4;
	}else if(c == '*' || c == '/'){
		return 3;
	}else if(c == '+' || c == '-'){
		return 2;
	}else{
		return 1;
	}
	
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string str;
		cin >> str;
		string result = "";
		stack<char> st;
		for(int i = 0;i < str.length();i++){
			char c = str[i];
			if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
				result += c;
			}else if(c == '('){
				st.push(c);
			}else if(c == ')'){
				while(!st.empty() && st.top() != '('){
					result += st.top();
					st.pop();
					
				}
				st.pop();
			}else{
				while(!st.empty() && pre(c) <= pre(st.top())){
					result += st.top();
					st.pop();
				}
				st.push(c);
			}
		}
		while(!st.empty()){
			result += st.top();
			st.pop();
		}
		cout << result << endl;
	}
}