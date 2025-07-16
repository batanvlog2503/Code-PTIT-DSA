#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, k;
		cin >> n>> k;
		
		vector<int> v(n);
		
		set<int> s;
		for(int i =0 ;i < n;i++){
			cin >> v[i];
			s.insert(v[i]);
		}
		vector<int> arr(s.begin(), s.end());
		
		sort(arr.begin(), arr.end());
		int count = 0;
		int left = 0, right = 1;
		
		while(right < arr.size()){
			if(arr[right] - arr[left] < k){
				count += right - left;
				right++;
			}else{
				left++;
				if(left  == right){
					right++;
				}
			}
		}
		cout << count <<endl;
	}
}