#include<iostream>
#include<queue>

using namespace std;

int main(){
	int q;
	cin >> q;
	cin.ignore();
	queue<int> V;
	while(q--){
		string str;
		cin >> str;
		
		
		if(str == "PUSH"){
			int x;
			cin >> x;
			V.push(x);
		}else if(str == "POP"){
			if(!V.empty()){
				V.pop();
			}
		}else if(str == "PRINTFRONT"){
			if(!V.empty()){
				cout << V.front();
			}else{
				cout << "NONE";
			}
			cout << endl;
		}
	}
}