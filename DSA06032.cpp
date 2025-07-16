#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int dem = 0;
		long long n, x;
		cin >> n >> x;
		long long a[n];
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		sort(a, a + n);
		long long count = 0;
		for(int i = 0;i < n - 2;i++){
			long long left = i + 1, right = n - 1;
			
			while(left < right){
				long long total = a[i] + a[left] + a[right];
				
				if(total < x){
					count+= right - left;
					left++;
				}else{
					right--;
				}
			}
		}
		cout << count<<endl;
	}
}