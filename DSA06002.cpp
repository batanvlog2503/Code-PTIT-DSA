#include<bits/stdc++.h>


using namespace std;
int n, k;
bool cmp(pair<int, int> a, pair<int, int> b){
	if(abs(k - a.first) != abs(k - b.first)){
		return abs(k - a.first) < abs(k - b.first);
	}
	return a.second < b.second;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n>>k;
		
		int a[n];
		vector<pair<int, int>> v;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			v.push_back(make_pair(a[i], i));
		}
		
		sort(v.begin(), v.end(), cmp);
		for(int i = 0;i < n;i++){
			cout << v[i].first << " ";
		}
		cout << endl;
	}
}