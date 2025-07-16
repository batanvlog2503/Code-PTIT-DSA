#include<iostream>
#include<set>
using namespace std;

int main(){
	int q;
	cin >>q;
	while(q--){
		int n, m;
		cin >> n >> m;
		
		int a[n], b[m];
		set<int> s;
		set<int> s1;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			s.insert(a[i]);
		}
		for(int i = 0;i < m;i++){
			cin >> b[i];
			if(s.find(b[i])!= s.end()){
				s1.insert(b[i]);
			}
			s.insert(b[i]);
			
		}
		for(auto x : s){
			cout << x << " ";
		}
		cout <<endl;
		for(auto x : s1){
			cout << x << " ";
		}
		cout <<endl;
	
	}
}