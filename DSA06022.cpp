#include<iostream>
#include<set>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		int a[n];
		set<int> s;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			s.insert(a[i]);
		}
		if(s.size() < 2){
			cout << -1;
		}else{
			int count = 0;
			for(auto x : s){
				if(count == 2){
					break;
				}
				cout << x<<" ";
				count++;
			}
		}
		cout <<endl;
		
	}
}