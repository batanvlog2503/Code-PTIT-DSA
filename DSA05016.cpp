#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		int i2 = 0, i3 = 0, i5 = 0, next2 = 2, next3 = 3, next5 = 5;
		
		vector<int> v(n);
		v[0] = 1;
		
		for(int i = 1;i < n;i++){
			int num = min({next2, next3, next5});
			v[i] = num;
			
			if(next2 == num){
				i2++;
				next2 = v[i2] * 2;
			}
			if(next3 == num){
				i3++;
				next3 = v[i3] * 3;
				
			}
			if(next5 == num){
				i5++;
				next5 = v[i5] * 5;
			}
		}
		cout << v[n - 1] <<endl;
	}
}