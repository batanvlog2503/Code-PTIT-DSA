#include<iostream>
#include<algorithm>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n, k,ok, b[1000], a[1000]; 

 
void khoitao(){
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
}
 
void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i){
		i--;
	}
	if(i == 0){
		ok = 0;
	}
	else {
		a[i]++;
		for(int j = i + 1; j <= k; j++){
			a[j] = a[j - 1] + 1;
		}
	}
}
 bool check(){
 	for(int i = 1;i <= k;i++){
 		if(b[i] != a[i]){
 			return false;
		 }
	 }
	 return true;
 }
int main() {
    int q;
     cin >> q;
     while(q--){
     	cin >> n >> k;
     	khoitao();
     	for(int i = 1;i <= k;i++){
     		cin >> b[i];
		 }
		 int count = 0;
		ok = 1;
		while(ok){
			if(check()){
				break;
			}
			count++;
			sinh();
		}
		cout << count + 1 <<endl;
	 }
}