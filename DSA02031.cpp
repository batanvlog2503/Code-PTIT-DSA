#include<bits/stdc++.h>


using namespace std;
char c;
vector<char> v;
int n;
vector<bool> visited;

bool kiemtra(vector<char> v){
	for(int i = 1;i < v.size() - 1;i++){
		if(v[i] == 'A' || v[i] == 'E'){
			if(v[i - 1] != 'A' && v[i - 1] != 'E' && v[i + 1] != 'A' && v[i + 1] != 'E'){
				return false;
			}
		}
	}
	return true;
}
void in(){
	if(kiemtra(v)){
		for(int i = 0;i < v.size();i++){
		cout << v[i];
	}
			cout << endl;
	}
}

void Try(int i){
	for(char j = 'A' ;j <=c;j++){
		if(visited[j - 'A']){
			visited[j - 'A'] = false;
			v[i] = j;
			if(i == n - 1){
				in();
			}else{
				Try(i + 1);
			}
			visited[j - 'A'] = true;
		}
	}
}
int main(){
	
	cin >> c;
	n = c - 'A' + 1;
	v.assign(n, 'A');
	visited.assign(n, true);
	Try(0);
}