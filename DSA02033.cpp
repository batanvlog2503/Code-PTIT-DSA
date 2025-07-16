#include<bits/stdc++.h>

using namespace std;
vector<int> x;
int n;
vector<bool> check;
bool kiemtra(vector<int> x){
	int n = x.size();
	map<int, int> mp;
	for(int i = 0;i < n;i++){
		if(x[i] == 0){
			return false;
		}
		mp[x[i]]++;
	}
	for(int i = 1;i < n;i++){
		if(abs(x[i] - x[i - 1]) == 1){
			return false;
		}
	}
	return true;
	
}
void in(){
	if(kiemtra(x)){
		for(int i = 0;i < x.size();i++){
		cout << x[i] ;
	}
	cout << endl;
	}
}
void Try(int i){
	for(int j = 1;j <= n;j++){
		if(check[j]){
			check[j] = false;
			x[i] = j;
			if(i == n - 1){
				in();
			}else{
				Try(i + 1);
			}
			check[j] = true;
		}
	}
}

int main(){
	int q;
	cin >> q;
	while(q--){
		
		cin >> n;
		x.assign(n, 0);
		check.assign(n + 1, true);
		Try(0);
		
	
		in();
	}
}