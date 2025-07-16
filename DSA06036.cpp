#include<iostream>
#include<algorithm>

using namespace std;


int main(){
	int q;
	cin >> q;
	while(q--){
		long long n, x;
		cin >> n>> x;
		
		long long a[n];
		
		for(int i = 0;i < n;i++) {
			cin >> a[i];
		}	
		bool check = false;
		
		sort(a, a + n);
		
		for(int i =0 ;i < n;i++){
			int j = i + 1, k = n - 1;
			
			while(j < k){
				long long total = a[j] + a[i] + a[k];
				
				if(total == x){
					check = true;
					break;
				}else if(total > x){
					k--;
				}else{
					j++;
				}
			}
		}
		if(check){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << endl;
	}
}