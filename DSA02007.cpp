#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int k;
		cin >> k;
		cin.ignore();
		
		
		string s;
		cin >> s;
		int count = 0;
		do{
			for(int i = 0;i < s.length();i++){
				cout << s[i];
			}
			cout << endl;
			count++;
		}while(next_permutation(s.begin(), s.end()) && count < k);
	}
}