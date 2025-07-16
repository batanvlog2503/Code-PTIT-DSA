#include<bits/stdc++.h>

using namespace std;
void to_lower(string &str){
	for(int i = 0;i <str.length();i++){
		str[i] = tolower(str[i]);
	}
	str[0] = toupper(str[0]);
}
void to_upper(string &str){
	for(int i =0 ;i < str.length();i++){
		str[i] = toupper(str[i]);
	}
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string str;
		getline(cin, str);
		
		stringstream ss(str);
		string num;
		string s = "";
		vector<string> v;
		while(ss >> num){
			to_lower(num);
			v.push_back(num);
		}
		for(int i = 1;i < v.size();i++){
			cout << v[i];
			if(i != v.size() - 1){
				cout <<" ";
			}
		}
		to_upper(v[0]);
		cout <<", "<<v[0];
		cout <<endl;
	}
}