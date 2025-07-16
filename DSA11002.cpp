#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		cin.ignore();
		
		vector<string> v;
		queue<int> q;
		for(int i = 0;i < n;i++){
			string s;
			cin >> s;
			v.push_back(s);
		}
		
		for(int i = v.size() - 1;i >= 0;i--){
			string c = v[i];
			
			if(c == "+" || c == "/" || c == "-" || c == "*"){
				int op1 = q.front();
				q.pop();
				int op2 = q.front();
				q.pop();
				
				if(c == "+"){
					q.push(op2  + op1);
				}else if(c == "-"){
					q.push(op2  - op1);
				}else if(c == "/"){
					q.push(op2  / op1);
				}else if(c == "*"){
					q.push(op2 * op1);
				}
				
			}else{
				q.push(stoi(c));
			}
			
		}
		cout << q.front() << endl;
	}
}