#include<iostream>
#include<vector>


using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> v;
		
		vector<int> a(n), b(m), c(k);
		
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		for(int j = 0;j < m;j++){
			cin >> b[j];
		}
		for(int j = 0;j < k;j++){
			cin >> c[j];
		}
		int i = 0, j = 0, o = 0;
		while(i < n && j < m && o < k){
			if(a[i] == b[j] && b[j] == c[o]){
				v.push_back(a[i]);
				i++;
				j++;
				o++;	
			}else if(a[i] < b[j]){
				i++;
			}else if(b[j] < c[o]){
				j++;
			}else{
				o++;
			}
		}
		if(v.empty()){
			cout << "NO";
		}else{
			for(int i = 0;i < v.size();i++){
				cout << v[i] << " ";
			}
			
		}
		cout << endl;
	}
}