#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		
		int n;
		cin >> n;
		cin.ignore();
		string s;
		cin >> s;
		vector<char> v(s.begin(), s.end());
		cout << n << " " ;
		if(next_permutation(v.begin(), v.end())){
			for(char x : v){
				cout << x;
			}
		}else{
			cout << "BIGGEST" ;
		}
		cout << endl;
		v.clear();
	}
}