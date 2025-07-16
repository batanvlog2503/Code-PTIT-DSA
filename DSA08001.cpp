#include<iostream>
#include<queue>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		queue<int> q;
		while(n--){
			int x;
			cin >> x;
			if(x == 1){
				cout << q.size() << endl;
			}else if(x == 2){
				if(q.empty()){
					cout <<"YES";
				}else{
					cout << "NO";
				}
				cout <<endl;
			}else if(x == 3){
				int y;
				cin >> y;
				q.push(y);
			}else if(x == 4){
				if(!q.empty()){
					q.pop();
				}
			}else if(x == 5){
				if(q.empty()){
					cout << -1;
				}else{
					cout << q.front();
				}
				cout << endl;
			}else{
				if(q.empty()){
					cout << -1;
				}else{
					cout << q.back();
				}
				cout << endl;
			}
				
			
		}
	}
}