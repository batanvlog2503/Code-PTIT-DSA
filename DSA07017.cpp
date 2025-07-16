#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> arr;
		for(int i = 0;i < n;i++){
			int x;
			cin >> x;
			arr.push_back(x);
		}
		
		stack<int> st;
		vector<int> res(n, -1);
		for(int i = n - 1;i >= 0;i--){
			while(!st.empty() && (arr[st.top()] >= arr[i] || arr[st.top()] <= arr[i])){
				st.pop();
			}
			
			if(!st.empty()){
				res[i] = st.top();
			}
			st.push(i);
		}
		for(int i = 0;i < n;i++){
			cout << res[i] << " ";
		}
		cout << endl;
	}
}