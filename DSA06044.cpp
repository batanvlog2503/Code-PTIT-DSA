#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	cin >> n;
	
	int a[n], b[n];
	vector<int> res1, res2;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(i % 2 == 0){
			res1.push_back(a[i]);
		}else{
			res2.push_back(a[i]);
		}
		
	}
	sort(res1.begin(), res1.end());
	sort(res2.begin(), res2.end(), greater<int>());
	int le = 0, chan = 0;
	
	for(int i = 0;i < n;i++){
		if(i % 2 == 0){
			cout <<res1[le++]<<" ";
		}else{
			cout <<res2[chan++]<<" ";
		}
	}
	
	
	
}