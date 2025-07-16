#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		for(int j = 0;j < m;j++){
			cin >> b[j];
		}
		sort(a,  a  + n);
		sort(b, b + n);
		int i = 0, j = 0;
		int arr[n + m], l = 0;
		while(i < n && j < m){
			if(a[i] <= b[j]){
				arr[l] = a[i];
				l++;
				i++;
			}else{
				arr[l] = b[j];
				l++;
				j++;
			}
		}
		while(i < n){
			arr[l] = a[i];
			i++;l++;
		}
		while(j < m){
			arr[l] = b[j];
			j++;
			l++;
		}
		for(int q = 0;q < n + m;q++){
			cout << arr[q] << " ";
		}
		cout << endl;
	}
}