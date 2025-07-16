#include<iostream>

using namespace std;
int arr[1000],n, ok;

void khoitao(){
	for(int i = 1;i <= n;i++){
		arr[i] = 0;
	}
}

void sinh(){
	int i = n;
	while(i > 0 && arr[i] == 1){
		arr[i] = 0;
		i--;
	}
	
	if(i == 0){
		ok = 0;
	}else{
		arr[i] = 1;
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
	ok = 1;
	khoitao();
	while(ok){
		
			for(int i = 1;i <= n;i++){
					if(arr[i] == 0){
						cout <<'A';
					}
					if(arr[i] == 1){
						cout << 'B';
						
					}
			}
		cout << " ";	
		sinh();
		
	}
	cout<<endl;
	}
	
}