#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	
	stack<string> st;
	string s = "Buoc 0: " + to_string(a[0]);
	st.push(s);
	int count = 1;
	for(int i = 1;i < n;i++){
		string str= "";
		int key = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
			str += "Buoc " + to_string(count) + ": ";
			
			for(int o = 0;o <= i;o++){
				str += to_string(a[o]) + " ";
			}
			st.push(str);
			count++;
	}
	
	while(!st.empty()){
		cout << st.top() << endl;
		st.pop();
	}
}