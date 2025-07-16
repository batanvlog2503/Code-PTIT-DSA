#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
	cin >> n;
	
	int a[n];
	
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int count = 1;
	stack<string> st ;
	
	for(int i = 0;i < n - 1;i++){
		bool check = false;
		string str = "";
		for(int j = i + 1;j < n;j++){
			if(a[i] >  a[j]){
				swap(a[i], a[j]);
				check = true;
			}
		}
		if(check){
			str += "Buoc " + to_string(count) + ": ";
			
			for(int o = 0;o < n;o++){
				str += to_string(a[o]) + " ";
			}
			st.push(str);
			count++;
		}
		
	}
	
	while(!st.empty()){
		cout << st.top()<<endl;
		st.pop();
		}
		cout<<endl;
	}
}