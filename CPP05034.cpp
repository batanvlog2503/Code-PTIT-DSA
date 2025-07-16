#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


const int MOD = 1e9 + 7;
void countways(int n, int k){
	vector<int> ways(n, 0);
	
	ways[0] = 1;// vì tại điểm 0 chỉ có 1 cách là đứng im
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= min(i, k);j++){
			ways[i] = (ways[i] + ways[i - j]) % MOD;
		}
	}
	
//	for(int i = 0;i < n;i++){
//		cout << ways[i] << " ";
//	}
cout << ways[n - 1] + ways[n - 2];
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n >> k;
		
		countways(n, k);
		cout <<endl;
	}
}