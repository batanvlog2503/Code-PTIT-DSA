#include<bits/stdc++.h>

using namespace std;
int pre(char c){
	if(c =='^'){
		return 4;
	}else if(c == '*' || c == '/'){
		return 3;
	}else if(c == '+' || c == '-'){
		return 2;
	}
	return 1;
}
vector<string> convert(string s){
	vector<string> result;
	for(int i =0 ;i < s.length();i++){
		if(isdigit(s[i])){
			string num = "";
			while(isdigit(s[i])){
				num += s[i];
				i++;
			}
			i--;
			if(num != ""){
				result.push_back(num);
			}
		}else{
			result.push_back(string(1, s[i]));
		}
	}
	return result;
}
vector<string> infix_to_postfix(vector<string> result){
	vector<string> ans
	stack<string> st;
	for(int i = 0;i < result.size();i++){
		string c = result[i];
		if(isalpha(c[0]) || isdigit(c[0])){
			result += c;
		}else if(c == "("){
			st.push(c);
		}else if(c == ")"){
			while(!st.empty() && st.top() != "("){
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
	return result;
	
}
long long res(vector<string> result){
	
	long long sum = 0;
	stack<long long> st;
	for(int i = .length() - 1;i>=0;i--){
		char c = s[i];
		if(c == '+' || c == '-' || c == '/' || c == '*'){
			long long op1 = st.top();
			st.pop();
			long long op2 = st.top();
			st.pop();
			if(c == '+'){
				st.push(op1 + op2);
			}else if(c == '-'){
				st.push(op1 - op2);
			}else if(c == '*'){
				st.push(op1 * op2);
			}else if(c == '/'){
				st.push(op1 / op2);
			}
		}else{
			
		}
	}
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string s;
		cin >> s;
		vector<string> result = convert(s);
		for(string s : result){
			cout <<s << " ";
		}
	//	string result = infix_to_postfix(s);
	//	cout << result << endl;
	}
}