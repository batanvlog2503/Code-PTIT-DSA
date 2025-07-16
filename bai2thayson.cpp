#include<bits/stdc++.h>

using namespace std;
int n, k, a[1000],ok;

void khoitao(){
	for(int i = 1;i <= k;i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i > 0 && a[i] == n - k + i){
		i--;
	}
	if(i == 0){
		ok = 0;
	}else{
		a[i]++;
		for(int j = i + 1;j <= k;j++){
			a[j] = a[j - 1] + 1;
		}
	}
}
int main(){
	cin >> n >> k;
	vector<int> v(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> v[i];
	}
	

	khoitao();
	ok = 1;
	vector<string> tmp;
	set<string> se;
	while(ok == 1){
		string result = "";
		for(int i = 1;i <= k;i++){
			result += to_string(v[a[i]]);			
		}
		if(se.find(result) == se.end()){
			tmp.push_back(result);
		}
		se.insert(result);
		
		sinh();
	}
	sort(tmp.begin(), tmp.end());
	for(string it : tmp){
		cout << it << endl;
	}
}