#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		vector<int> v;
		int a[n];
		
		for(int i = 0; i < n;i++){
			cin >> a[i];
		}
		for(int i = 0;i <= n - k;i++){
			int res = a[i];
			
			for(int j = 0;j < k;j++){
				if(a[i + j] > res){
					res = a[i + j];
				}
			}
			v.push_back(res);
		}
		
		for(int i = 0;i < v.size();i++){
			cout << v[i] << " ";
		}
		cout <<endl;
	}
}