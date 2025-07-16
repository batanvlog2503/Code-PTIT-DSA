/// xâu fibonacci

//divide and conquer

#include<bits/stdc++.h>

using namespace std;
long long find(long long n,long long k){
	if(k == (long long)pow(2, n - 1)){
		return n;
	}else if(k < (long long)pow(2, n - 1)){
		return find(n - 1, k);// nửa trái
	}
	return find(n - 1, k - (long long)pow(2, n - 1)); // nửa phải
}
int main(){
	int q;
	cin >> q;
	while(q--){
	long long n, k;
		cin >> n >> k;
		cout << find(n, k) << endl;
	}
}