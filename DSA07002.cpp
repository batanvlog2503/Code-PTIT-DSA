#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

int main(){
	int q;
	cin >> q;
	cin.ignore();
	stack<int> st;
	
	while(q--){
		string str;
		cin >> str;
		
		if(str == "PUSH"){
			int x;
			cin >> x;
			st.push(x);
		}else if(str == "POP"){
			if(!st.empty()){
				st.pop();
			}
		}else if(str == "PRINT"){
			if(st.empty()){
				cout << "NONE";
			}else{
				cout << st.top();
			}
			cout << endl;
		}
	}
}