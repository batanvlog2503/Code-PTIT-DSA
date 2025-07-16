#include<iostream>

using namespace std;
int arr[] = {1, 2, 5,10,20, 50, 100, 200, 500, 1000};
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		
		
		int count = 0;
		for(int i =9;i >= 0;i--){
			while(arr[i] <= n){
				n-=arr[i];
				count++;
			}
		}
		cout << count << endl;
	}
}