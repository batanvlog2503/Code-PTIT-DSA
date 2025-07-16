#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[1000], n, ok;
void khoitao(){
	for(int i = 1;i <= n;i++){
		a[i] = 0;
	}
}
void sinh(){
	int i = n;
	
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == 0){
		ok = 0;
	}else{
		a[i] = 1;
	}
}
bool check1(){
	if(n < 6){
		return false;
	}
	if(a[1] != 0 || a[n] != 1){
		return false;
	}
	for(int i = 2;i <= n;i++){
		if(a[i] == 0 && a[i] == a[i - 1]){
			return false;
		}
	}
	int dem = 1;
	int res = -1e9 - 7;
	for(int i = 2;i <= n;i++){
		if(a[i] == 1 && a[i] == a[i - 1]){
			dem++;
		}else{
			dem = 1;
		}
		res = max(res, dem);
	}
	res = max(res, dem);
	if(res > 3){
		return false;
	}
	return true;
}
int main(){
	cin >> n;
	khoitao();
	ok = 1;
	vector<string> s;
	while(ok){
		string str = "";
		if(check1()){
			for(int i = 1;i <= n;i++){
				if(a[i] == 0){
					str += '8';
				}
				if(a[i] == 1){
					str += '6';
				}
				
			}
			s.push_back(str);
		
		}
		sinh();
		
	}
	sort(s.begin(), s.end());
	
	for(int i = 0;i < s.size();i++){
		cout << s[i] << endl;
	}
}