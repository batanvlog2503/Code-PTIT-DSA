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
		
		vector<int> res(n, -1);
		
		stack<int> st;
		st.push(a[n - 1]);
		for(int i = n - 2;i >= 0;i--){
			while(!st.empty() && st.top() <= a[i]){
				st.pop();
			}
			
			if(!st.empty()){
				res[i] = st.top();
			}
			
			st.push(a[i]);
		}
		
		for(int i = 0 ;i <n ;i++){
			cout << res[i] << " ";
		} 
		cout << endl;
	}
}