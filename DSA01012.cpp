#include<bits/stdc++.h>

using namespace std;
string convert(int num, int n){
	string res = "";
	while(num){
		int r = num % 2;
		res += to_string(r);
		num /= 2;
	}
	while(res.length() < n){
		res += '0';
	}
	reverse(res.begin(), res.end());
	return res;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<string> result;
		//dich trai hiểu đơn giản là lấy i * 2 ^ số cần dịch
		for(int i = 0;i < (1 << n);i++){
			int gray = i ^ (i >> 1);
			result.push_back(convert(gray, n));
		}
		for(string it : result){
			cout << it << " ";
		}
		cout << endl;
		
	}
	
}