#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		long long n, k;
        cin >> n >> k;
        long long a[n];

        for(long long i = 0; i < n; i++){
            cin >> a[i];
        }
        long long idx = 0, res = 0;
        sort(a, a + n);
        for(int i = 0;i < n;i++){
            if(i < k){
                idx -= a[i];
            }else{
                idx += a[i];
            }
            if(i < n-k){
                res -= a[i];

            }else{
                res += a[i];
            }
        }
        cout << max(idx, res) << endl;

	}	
}