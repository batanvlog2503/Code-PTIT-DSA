#include<iostream>
#include<algorithm>
#include<stack>
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
	stack<string> st;
	for(int i = 0;i < n;i++){
		bool check = false;
		string str = "";
		for(int j = 0;j < n - i - 1;j++){
			if(a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
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
		cout << st.top() << endl;
		st.pop();
	}
	}
}