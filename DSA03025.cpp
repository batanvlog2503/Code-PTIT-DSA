#include<bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<pair<int, int>> v;
		for(int i = 1;i <= n;i++){
			int x, y;
			cin >> x >> y;
			v.push_back({x, y});
		}
		
		sort(v.begin(), v.end(),[](pair<int, int> &a, pair<int,int> &b){
			return a.second < b.second;
		});
		
		int pos = 0, res = 0, ans = 1;
		
		for(int i = 0;i < v.size();i++){
			pair<int, int> p = v[i];
			
			if(p.first >= pos){
				pos = p.second;
				res++;
				ans = max(res, ans);
			}
		}
		cout << ans << endl;
	}
}