#include<bits/stdc++.h>

using namespace std;
bool check(string s){
	if(s == "+" || s == "-" || s == "*" || s == "/"){
		return true;
	}
	return false;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		stack<long long > st;
		vector<string> tmp;
		for(int i = 0 ;i < n;i++){
			cin.ignore();
			string s;
			cin >> s;
			tmp.push_back(s);
			
		}
		if(check(tmp[0])){
			for(int i = n - 1;i >= 0;i--){
			if(check(tmp[i])){
				long long op1 = st.top();
				st.pop();
				long long op2 = st.top();
				st.pop();
				
				if(tmp[i] == "+"){
					st.push(op1 + op2);
				}else if(tmp[i] == "-"){
					st.push(op1 - op2);
				}else if(tmp[i] == "/"){
					st.push(op1 / op2);
				}else if(tmp[i] == "*"){
					st.push(op1 * op2);
				}
			}else{
				st.push(stoll(tmp[i]));
			}
		}
			cout << st.top() << endl;
		}else{
			for(int i = 0;i < n;i++){
			if(check(tmp[i])){
				long long op1 = st.top();
				st.pop();
				long long op2 = st.top();
				st.pop();
				
				if(tmp[i] == "+"){
					st.push(op2 + op1);
				}else if(tmp[i] == "-"){
					st.push(op2 - op1);
				}else if(tmp[i] == "/"){
					st.push(op2 / op1);
				}else if(tmp[i] == "*"){
					st.push(op2 * op1);
				}
			}else{
				if(isdigit(tmp[i][0]) || (tmp[i].length() > 1 && tmp[i][0] =='-')){
					st.push(stoll(tmp[i]));
				}
			}
		}
			cout << st.top() << endl;
		}
		
	}
}
