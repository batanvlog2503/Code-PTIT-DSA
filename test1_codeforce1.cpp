#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0;i < n;i++){
		v[i] = i + 1;
	}
	
	do{
		if(v[0] == m){
			for(int i = 0;i < n;i++){
				cout << v[i] <<" ";
			}
			cout << "\n";
		}
	}while(next_permutation(v.begin(), v.end()));
}