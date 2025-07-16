#include<iostream>
#include<map>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		long long n, k;
		cin >> n >> k;
		long long a[n];
		for(int i = 0;i <n;i++){
			cin >> a[i];
			
		}
		map<long long, long long> mp;
		long long count  = 0;
		for(int i = 0;i < n;i++){
			long long x = k - a[i];
			
			if(mp.find(x) != mp.end()){
				count += mp[x];
			}
			mp[a[i]]++;
		}
		
		cout << count << endl;
	}
}