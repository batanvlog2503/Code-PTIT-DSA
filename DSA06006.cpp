//while (mid <= hi) {
//        if (arr[mid] == 0)
//            swap(arr[lo++], arr[mid++]);
//        else if (arr[mid] == 1)
//            mid++;
//        else
//            swap(arr[mid], arr[hi--]);
//    }

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int a[n];
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		
		int left = 0, mid = 0, right = n - 1;
		
		while(mid <= right){
			if(a[mid] == 0){
				swap(a[mid++], a[left++]);
			}else if(a[mid] == 1){
				mid++;
			}else{
				swap(a[mid], a[right--]);
			}
		}
		
		for(int i = 0;i < n;i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}