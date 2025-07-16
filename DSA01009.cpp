#include<bits/stdc++.h>

using namespace std;
int a[10001], n, ok, k;

bool check(){
	int count = 0, dem =0 ;;
	map<int, int> mp;
	for(int i = 1;i <= n;i++){
		if(a[i] == 1){
			count++;
		}else{
			if(count == k){
				dem++;
			}
			count = 0;
		}
	}
	if(count == k){
		dem++;
	}
	if(dem == 1){
		return true;
	}else{
		return false;
	}
}
void khoitao(){
	for(int i = 1;i <= n;i++){
		a[i] = 0;
	}
}
void sinh(){
	int i = n;
	
	while(i > 0 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == 0){
		ok = 0;
	}else{
		a[i] = 1;
	}
}
int main(){
	cin >> n >> k;
	khoitao();
	ok = 1;
	vector<string> s;
	while(ok){
		if(check()){
			string str = "";
			for(int i = 1;i <= n;i++){
				if(a[i] == 1){
					str+='A';
				}else{
					str+='B';
				}
			}
			s.push_back(str);
			
		}
		sinh();
	}
	cout << s.size()<<endl;
	sort(s.begin(), s.end());
	for(int i = 0 ;i < s.size();i++){
		cout << s[i] <<endl;
	}
}