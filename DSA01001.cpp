#include<iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string str;
		cin >> str;
		int i = str.length() - 1;
		int ok;
		ok = 1;
		while(i >= 0 && str[i] == '1'){
			str[i] = '0';
			i--;
		}
		if(i < 0){
			ok = 0;
		}else{
			str[i] = '1';
		}
		
		if(ok){
			for(int i = 0;i < str.length();i++){
				cout << str[i];
			}
			
		}else{
			for(int i = 0;i < str.length();i++){
				cout << '0';
			}
		}
		cout<<endl;
		
	}
}