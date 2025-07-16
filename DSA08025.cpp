#include<bits/stdc++.h>

using namespace std;

bool visited[1001];
int d[1001][1001];
int a[1001][1001];
int dx[8] = {-2, -2, -1, -1, 1, 1,2, 2};
int dy[8] = {-1, 1, -2 , 2, -2, 2, -1,1};
int convert(char x){
	if(x == 'a') return 1;
	if(x == 'b') return 2;
	if(x == 'c') return 3;
	if(x == 'd') return 4;
	if(x == 'e') return 5;
	if(x == 'f') return 6;
	if(x == 'g') return 7;
	if(x == 'h') return 8;
	return 0;
}

void bfs(int s, int t){
	queue<pair<int, int>> q;
	q.push({s, t});
	a[s][t] = 1;
	d[s][t] = 0;
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		
		for(int k = 0;k < 8;k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			
			if(i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && a[i1][j1] == 0){
				d[i1][j1] = d[top.first][top.second] + 1;
				q.push({i1, j1});
				a[i1][j1] = 1;
			}
		}
	}
}
int main(){
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		string s1, s2;
		cin >> s1 >> s2;
		memset(visited, false, sizeof(visited));
		memset(d, 0, sizeof(d));
		memset(a, 0, sizeof(a));
		int s = convert(s1[0]);
		int t = s1[1] - '0';
		int u = convert(s2[0]);
		int v = s2[1] - '0';
		bfs(s, t);
		
		cout << d[u][v] << endl;
	}
}