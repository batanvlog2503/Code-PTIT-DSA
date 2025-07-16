#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int ok;
void sinh(vector<char> &arr){
	int n = arr.size();
	int i = n - 2;
	while(i >= 0 && arr[i] > arr[i + 1]){
		i--;
	}
	
	if(i < 0){
		ok = 0;
	}else{
		int j = n - 1;
		while(arr[i] > arr[j]){
			j--;
		}
		swap(arr[i], arr[j]);
		int l = i + 1, r = n  - 1;
		
		reverse(arr.begin() + l, arr.begin() + r + 1);
	}
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string str;
		cin >> str;
		
		vector<char> arr;
		for(char x : str){
			arr.push_back(x);
		}
		ok = 1;
		while(ok){
			for(int i =0; i< arr.size();i++){
				cout << arr[i];
			}
			cout << " ";
			sinh(arr);
		}
		cout <<endl;
		
		
	}
}