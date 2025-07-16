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
		for(int i = n - 1;i >= 0;i--){
			char c = str[i];
			
			if(isdigit(c)){
				st.push(stoll(string (1,str[i])));
			}else{
				long long val1 = st.top();
				st.pop();
				long long val2 = st.top();
				st.pop();
				
				if(c == '*'){
					st.push(val1 * val2);
				}else if(c == '+'){
					st.push(val1 + val2);
				}else if(c == '-'){
					st.push(val1 - val2);
				}else if(c == '/'){
					st.push(val1 / val2);
				}
			}
			
		}
		cout << st.top() << endl;
	}
}