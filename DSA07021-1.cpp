#include<bits/stdc++.h>

using namespace std;
int longest_valid_parentheness(string s){
	stack<int> st;
	st.push(-1); // xử lí s[0] = )
	int max_len = INT_MIN;
	
	for(int i = 0;i < s.length();i++){
		char x = s[i];
		if(x == '('){
			st.push(i);
		}else{
			st.pop();
			
			if(st.empty()){
				st.push(i);
			}else{
				max_len = max(max_len, i - st.top());
			}
		}
	}
	return max_len;
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string s;
		cin >> s;
		cout << longest_valid_parentheness(s);
		cout << endl;
	}
}