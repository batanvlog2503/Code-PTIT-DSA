#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

int main(){
	string str;
	stack<string> st;
	vector<int> v;
	
	while(cin >> str){
		if(str == "push"){
			int x;
			cin >> x;
			v.push_back(x);
		}else if(str == "show"){
			if(v.size() == 0){
				cout << "empty";
				cout << endl;
			}else{
				for(int i =0 ;i < v.size();i++){
					cout << v[i] << " ";
				}
				cout << endl;
			}
		}else if(str == "pop"){
			v.pop_back();
		}
	}
}