#include<iostream>
#include<vector>
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n;
		cin >> n;
		vector<long long> a(n);
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		
		vector<long long> prefix(n + 1);
		prefix[0] = a[0];
		
		for(int i = 1;i < n;i++){
			prefix[i] = prefix[i - 1] + a[i];
		}
		bool check = true;
		for(int i = 1;i < n -1;i++){
			if(prefix[i - 1] == prefix[n - 1] - prefix[i]){
				cout << i + 1;
				check = false;
				break;
			}
		}
		if(check == true){
			cout << -1;
		}
		cout << endl;
	}
}