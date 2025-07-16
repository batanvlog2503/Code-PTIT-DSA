#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> a(n);
		int l = 1e9 + 7, r = -1e9 - 7;
		set<int> s;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			l = min(l, a[i]);
			r = max(r, a[i]);
			s.insert(a[i]);
		}
		int count = 0;
		
		cout << r - l +  1 - s.size() << endl;
	}
}