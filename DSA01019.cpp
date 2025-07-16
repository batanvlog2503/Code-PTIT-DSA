#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[1000], ok, n, k;

void khoitao(){
	for(int i = 0;i < n;i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n - 1;
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
// quy định H là 0 A là 1
bool check(){
	if(a[0] != 0){
		return false;
	}
	if(a[n - 1] != 1){
		return false;
	}
	for(int i = 1;i < n;i++){
		if(a[i] == 0 && a[i] == a[i - 1]){
			return false;
		}
	}
	return true;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		ok = 1;
		khoitao();
		vector<string> v;
		while(ok){
			
			if(check()){
				string str = "";
				for(int i = 0;i < n;i++){
					if(a[i] == 0){
						
						str += 'H';
					}
					if(a[i] == 1){
				
						str += 'A';
					}
					
				}
				v.push_back(str);
				
			}
			sinh();
		}
		sort(v.begin(), v.end());
		for(int i = 0;i < v.size();i++){
			cout << v[i] << endl;
		}
		
	}
}