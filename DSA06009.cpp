#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin>> q;
	while(q--){
		int n, target;
		cin >> n >> target;
		vector<int> a(n);
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		
		unordered_map<int,int> mp;
		int count = 0;
		
		for(int i = 0;i < n;i++){
			int x = target - a[i];
			if(mp.find(x) != mp.end()){
				count += mp[x];
			}
			mp[a[i]]++;
		}
		cout << count<<endl;
	}
}