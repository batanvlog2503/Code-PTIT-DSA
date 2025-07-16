#include<iostream>

using namespace std;

bool check(string a){
	if(a[0] != a[a.length() - 1]){
		return false;
	}
	return true;
}

int main(){
	int q;
	cin >> q;
	cin.ignore();
	
	while(q--){
		string s;
		cin >> s;
		if(check(s)){
			cout << "YES";
		}else{
			cout <<"NO";
		}
		cout <<endl;
	}
}