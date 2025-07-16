#include<bits/stdc++.h>

using namespace std;
bool check(string s){
	if(s =="+" || s== "-" || s == "/" || s == "*"){
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
		
		
		stack<long long> st;
		for(int i = 0;i < n;i++){
			cin.ignore();
			string num;
			cin >> num;
			if(check(num)){
				long long op1 = st.top();
				st.pop();
				long long op2 = st.top();
				st.pop();
				
				if(num == "+"){
					st.push(op2 + op1);
				}else if(num == "-"){
					st.push(op2 - op1);
				}else if(num == "/"){
					st.push(op2 / op1);
				}else if(num == "*"){
					st.push(op2 * op1);
				}
			}else{
				st.push(stoll(num));
			}
		}
			
		
		
		
		
		cout << st.top() << endl;
	}
}