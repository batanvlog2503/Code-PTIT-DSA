#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		if(n % 2 != 0){
			cout <<0;
		}else{
			map<int, int> mp;
			
			for(int i = 2;i *i <= n;i++){
				while(n % i == 0){
					mp[i]++;
					n/=i;
				}
			}
			if(n > 1){
				mp[n]++;
			}
			cout << mp[2];
		}
		cout <<endl;
	}
}