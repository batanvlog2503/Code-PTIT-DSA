#include<iostream>
#include<map>
using namespace std;

int main(){
	int q;
	cin >> q;
	for(int j = 1;j <= q;j++){
		int n;
		cin >> n;
		map<int, int> mp;
		for(int i = 2;i * i <= n;i++){
			while(n % i == 0){
				mp[i]++;
				n/=i;
			}
		}
		if(n > 1){
			mp[n]++;
		}
		cout << "Test "<<j<<": ";
		for(auto x : mp){
			cout << x.first <<"("<<x.second<<") ";
		}
		cout <<endl;
	}
}