#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v, int l, int r, int m){
	vector<int> x(v.begin() + l, v.begin() + m + 1);
	vector<int> y(v.begin() + m + 1, v.begin() + r + 1);
	int i = 0, j = 0, n1 = x.size(), n2 = y.size();
	
	while(i < n1 && j < n2){
		if(x[i] <= y[j]){
			v[l] = x[i];
			l++;
			i++;
		}else{
			v[l] = y[j];
			j++;
			l++;
		}
	}
	while(i < n1){
		v[l] = x[i];
		l++;
		i++;
	}
	while(j < n2){
		v[l] = y[j];
		j++;l++;
	}
}


void mergeSort(vector<int> &v, int l, int r){
	if(l >= r){
		return ;
	}
	
	int m = (l + r) / 2;
	
	mergeSort(v, l, m);
	mergeSort(v, m + 1, r);
	merge(v, l, r, m);
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		
		vector<int> v(n);
		
		for(int i = 0;i < n;i++){
			cin >> v[i];
		}
		int l = 0, r = n - 1;
		mergeSort(v, l, r);
		
		for(int i = 0;i < n;i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}
}