#include<iostream>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, m;
		cin >> n >> m;
		long long a[n],b[m];
		long long maxx = -1e9 - 7, minx = 1e9 + 7;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			maxx = max(maxx, a[i]);
		}
		for(int i = 0;i < n;i++){
			cin >> b[i];
			minx = min(minx, b[i]);
		}
		
		cout << minx * maxx << endl;
	}
}