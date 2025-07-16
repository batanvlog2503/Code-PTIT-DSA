#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(vector<int> res){
	for(int i  =1;i < res.size();i++){
		if(res[i - 1] >= res[i]){
			return false;
		}
	}
	return true;
}
void backtrack(int idx, vector<int> &arr, vector<int> &res, vector<vector<int>> &tmp){
	if(idx == arr.size()){
		if(res.size() >= 2 && check(res)){
			tmp.push_back(res);
		}
		return ;
	}
	
	res.push_back(arr[idx]);
	backtrack(idx + 1, arr, res, tmp);
	res.pop_back();
	backtrack(idx + 1, arr, res, tmp);
}
int main(){
	int n;
	cin >> n;
	
	vector<int> arr(n);
	
	for(int i =0 ;i < n;i++){
		cin >> arr[i];
	}
	
	vector<int> res;
	vector<vector<int>> tmp;
	backtrack(0, arr, res, tmp);

	vector<string> v;
	for(vector<int> it: tmp){
		string str ="";
		for(int i = 0;i < it.size();i++){
			str += to_string(it[i]);
			
			if(i != it.size() - 1){
				str += " ";
			}
		}
		v.push_back(str);
		
	}
	sort(v.begin(), v.end());
	
	for(string x : v){
		cout << x<<endl;
	}
}