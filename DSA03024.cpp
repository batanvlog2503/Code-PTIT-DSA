#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> a, b;
		for(int i = 1;i <= n;i++){
			int x, y;
			cin >> x >> y;
			a.push_back(x);
			b.push_back(y);
			
		}
		vector<pair<int, int>> res;
		for(int i = 0;i <n;i++){
			res.push_back({a[i], b[i]});
		}
		sort(res.begin(), res.end(), [](pair<int, int>& a, pair<int, int> &b){
			return a.second < b.second;
		});
		int pos = 0, dem = 0, ans = 1;
		for(int i = 0; i < res.size();i++){
			pair<int,int> p = res[i];
			if(p.first >= pos){
				pos = p.second;
				dem++;
				ans = max(ans, dem);
			}
		}
		cout << ans <<endl;
	}
}