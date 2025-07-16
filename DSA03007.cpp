#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
	int q;
	cin >> q;
	
	while(q--){
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		
		for(int i =0 ;i < n;i++){
			cin >> a[i];
		}
		for(int j = 0;j < n;j++){
			cin >> b[j];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());
		
		long long ans = 0;
		
		for(int i =0;i < n;i++){
			ans = ans + a[i] * b[i];
		}
		cout << ans << endl;
	}
}
