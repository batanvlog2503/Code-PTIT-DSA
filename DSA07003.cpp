#include<bits/stdc++.h>

using namespace std;
// check ngo?c th?a
bool check(string s){
	stack<char> st;
	for(int i = 0;i < s.length();i++){
		char c = s[i];
		if(c == ')'){
			bool hasoperator = false;
			while(!st.empty() && st.top() != '('){
				char x = st.top();
				st.pop();
				if(x == '+' || x =='-' || x =='/' || x =='*'){
					hasoperator = true;
				}
			}
			if(!st.empty()){
				st.pop();
			}
			if(!hasoperator) return true; // thua ngoac
			
		}else{
			st.push(c);
		}
	}
	return false;
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string s;
		cin >> s;
		
		if(check(s)){
			cout << "Yes";
		}else{
			cout <<"No";
		}
		cout << endl;
	}
}