#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string s;
		cin >> s;
		stack<string> st;
		
		for(int i = 0 ;i < s.size();i++){
			char c = s[i];
			
			if(isalpha(c)){
				st.push(string(1, c));
			}else{
				string k = st.top();
				st.pop();
				k = c + k;
				k = st.top() + k;
				
				st.pop();
				st.push(k);
			}
		}
		cout << st.top() << endl;
	}
}