#include<iostream>
#include<map>
using namespace std;

int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string str;
		cin >> str;
		map<char,int> mp;
		for(int i = 0;i < str.length();i++){
			mp[str[i]]++;
		}
		bool check =true;
		for(auto x : mp){
			if(x.second * 2 - 1 > str.length()){
				check = false;
			}
		}
		if(check){
			cout << '1';
		}else{
			cout <<"-1";
		}
		cout << endl;
	}
}