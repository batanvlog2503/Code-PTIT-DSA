#include<iostream>
#include<queue>

using namespace std ;
vector<string> res;


void init(){
	queue<string> q;
	
	q.push("1");
	res.push_back("1");
	
	while(res.size() < 10001){
		string top = q.front();
		
		q.pop();
		
		res.push_back(top + "0");
		res.push_back(top + "1");
		q.push(top + "0");
		q.push(top + "1");
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		init();
		for(int i = 0;i <n;i++){
			cout << res[i]<<" ";
		}
		cout << endl;
	}
}