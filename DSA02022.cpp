#include<bits/stdc++.h>

using namespace std;


int a[1000], ok;
void khoitao(){
	for(int i = 0;i < 8;i++){
		a[i] = 0;
	}
}

bool check(){
	if(a[0] == 0 && a[1] == 0){
		return false;
	}
	if(a[4] == 0){
		return false;
	}
	if(a[2] == 1 && (a[3] == 1 || a[3] == 0)){
		return false;
	}
	if(a[2] == 0 && a[3] == 0){
		return false;
	}
	return true;
}
void sinh(){
	int i = 7;
	while(i >= 0 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i < 0){
		ok = 0;
	}else{
		a[i] = 1;
	}
}
int main(){
	
	khoitao();
	ok = 1;
	vector<string> v;
	while(ok == 1){
		
		if(check()){
			string result = "";
			for(int i = 0;i < 8;i++){
				if(a[i] == 1){
					result += '2';
				}else{
					result += '0';
				}
				if(i == 3 || i == 1){
					result +='/';
				}
			}
			v.push_back(result);
		}
		
	
		sinh();
	}
	sort(v.begin(), v.end());
	for(string it : v){
		cout << it << endl;
	}
	
}