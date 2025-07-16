#include<iostream>
#include<map>
using namespace  std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		int a[n];
		int res = -1e9 - 7;
		int x ;
		map<int, int> mp;
		for(int i = 0;i < n;i++) {
			cin >> a[i];
			mp[a[i]]++;
			if(mp[a[i]] > res){
				res = mp[a[i]];
				x = a[i];
			}
		}
		if(res > n / 2){
			cout << x;
		}else{
			cout << "NO";
		}
		cout <<endl;
		bool check = false;
		
		
		
	}
}