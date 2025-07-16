#include<bits/stdc++.h>

using namespace std;

int init(int s, int t){
	queue<pair<int, int>> q;
	
	set<int> se;
	se.insert(s);
	q.push({s, 0});
	int res = 0;
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		if(top.first == t){
			res = top.second;
			break;
		}
		if(top.first - 1 == t || top.first * 2 == t){
			res = top.second + 1;
			break;
		}
		if(se.find(top.first - 1) == se.end() && top.first > 1){
			q.push({top.first - 1, top.second + 1});
			se.insert(top.first - 1);
		}
		if(se.find(top.first * 2) == se.end() && top.first < t){
			q.push({top.first * 2, top.second + 1});
			se.insert(top.first * 2);
		}
	}
	return res;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int s, t;
		cin >> s >> t;
		
		cout << init(s, t) << endl;
	}
}