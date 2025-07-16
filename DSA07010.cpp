#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string str;
		
		cin >> str;
		
		string result = "";
		
		stack<string> st;
		
		int n = str.length();
		
		for(int i = n - 1;i >= 0;i--){
			char c = str[i];
			
			if(isdigit(c) || isalpha(c)){
				st.push(string(1, c));
			}else{
				string op1 = st.top();st.pop();
				string op2 = st.top();st.pop();
				
				string temp = op1 + op2 + c;
				st.push(temp);
			}
		}
		cout << st.top()<<endl;
	}
	

}