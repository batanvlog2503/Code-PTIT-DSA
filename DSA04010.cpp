#include<iostream>
#include<vector>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> a(n);
		
		for(int i =0 ;i < n;i++){
			cin >> a[i];
		}
		int sum1 = 0, sum2 = 0;
		
		for(int i =0 ;i < n;i++){
			sum1 += a[i];
			if(sum1 < 0){
				sum1 = 0;
			}
			sum2 = max(sum1, sum2);
		}
		cout << sum2<<endl;
	}
}