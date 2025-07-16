#include<iostream>
#include<vector>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, m, k;
		cin >> n >> m >> k;
		
		vector<int> arr1(n), arr2(m);
		
		for(int i =0 ;i < n;i++){
			cin >> arr1[i];
		}
		for(int i =0 ;i < m;i++){
			cin >> arr2[i];
		}
		
		int i =0 , j = 0;
		vector<int> v(n + m);
		int idx = 0;
		
		while(i < n && j < m){
			if(arr1[i] <= arr2[j]){
				v[idx] = arr1[i];
				idx++;
				i++;
			}else{
				v[idx] =arr2[j];
				j++;
				idx++;
			}
		}
		
		while(i < n){
			v[idx] = arr1[i];
				idx++;
				i++;
		}
		while(j < m){
			v[idx] = arr2[j];
				idx++;
				j++;
		}
		cout << v[k - 1] << endl;
	}
}