#include<iostream>
#include<stack>

using namespace std;

bool check(string str){
	stack<char> st;
	
	for(char c : str){
		if(c == '(' || c == '{' || c == '['){
			st.push(c);
		}else{
			if(!st.empty() && (
			(st.top() == '(' && c ==')') ||
			(st.top() == '{' && c =='}') ||
			(st.top() == '[' && c ==']'))){
				st.pop();
			}else{
				return false;
			}
		}
	}
	if(st.empty()){
		return true;
	}else{
		return false;
	}
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string str;
		cin >> str;
		
		if(check(str)){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << endl;
		
	}
}