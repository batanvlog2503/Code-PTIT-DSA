#include<iostream>
#include<algorithm>
using namespace std;

int a[1000], n, ok;

void khoitao(){
	for(int i = 1;i <= n;i++){
		a[i] = n - i + 1;
	}
}

bool sinh(){
	return prev_permutation(a + 1, a + n + 1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		khoitao();
		
	 do {
            for (int i = 1; i <= n; i++) {
                cout << a[i];
            }
            cout << " ";
        } while (sinh());
		cout << endl;
	}
}