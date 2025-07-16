#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	cout << "Buoc 0: " << a[0]<<endl;
	int count = 1;
	for(int i = 1;i < n;i++){
		int key = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		cout <<"Buoc "<< count <<": ";
		for(int k = 0;k <= i;k++){
			cout << a[k] << " ";
		}
		cout <<endl;
		count++;
	}
}