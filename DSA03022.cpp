#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin >> n;
	
	vector<long long> a(n);
	
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	long long res1 = a[0] * a[1];
	long long res2 = a[0] * a[1] * a[2];
	long long res3 = a[0] * a[1] * a[n - 1];
	long long res4 = a[n - 1] * a[n - 2] * a[n - 3];
	
	cout << max({res1, res2, res3, res4})<<endl;
}