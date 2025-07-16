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
		
		stack<int> st;
		int n = str.length();
		for(int i = 0;i < n;i++){
			char c = str[i];
			
			if(isdigit(c)){
				st.push(stoll(string(1, c)));
			}else{
				long long op1 = st.top();
				
				st.pop();
				long long op2 = st.top();
				
				st.pop();
				
				if(c == '*'){
					st.push(op1 * op2);
				}else if(c == '+'){
					st.push(op2 + op1);
				}else if(c == '-'){
					st.push(op2 - op1);
				}else if(c == '/'){
					st.push(op2 / op1);
				}
			}
		}
		
		cout << st.top()<<endl;
		
	}
}