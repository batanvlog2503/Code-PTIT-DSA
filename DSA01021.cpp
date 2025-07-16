#include<iostream>
#include<set>
using namespace std;
int n, k, a[1000], ok;


void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i){
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
	int t;
	cin >> t;
	while(t--){
		
		ok = 1;
		cin >> n >> k;
		set<int> s;
		for(int i = 1;i <= k;i++){
			cin >> a[i];
			s.insert(a[i]);
		}
		sinh();
		int count = 0;
		if(ok){
				for(int i = 1;i <= k;i++){
			if(s.find(a[i]) == s.end()){
				count++;
			}
			s.insert(a[i]);
		}
		cout<<count;
		}else{
			cout << k;
		}
		
		cout<<endl;
	}
}