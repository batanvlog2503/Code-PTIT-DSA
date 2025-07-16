#include<bits/stdc++.h>

using namespace std;

string str(int n, int s){
	int num = 9 * n;
	
	if(s > num){
		return "-1";
	}
	
	if(s == 0 && n > 1){
		return "-1";
	}
	
	string result = "";
	for(int i = 0;i < n;i++){
		if(s >= 9){
			result += '9';
			s -= 9;
		}else{
			result += to_string(s);
			s = 0;
		}
	}
	
	
	return result;
}
int main(){
	int n, s;
	cin >> n >> s;
	string result = str(n, s);
	if(result == "-1"){
		cout << -1 <<" " << -1;
	}else{
		string s1 = result;
		while(s1.length() < n){
			s1 += "0";
		}
		reverse(result.begin(), result.end());
		string s2 = result;
		
		
		
//		while(s2[0] == '0'){
//			s2.erase(0, 1);
//		}
//		while(s2.length() < n){ // s2 nhỏ hơn
//			s2.insert(1, "0");
//		}
		if(s2[0] == '0'){
    		for(int i = 1; i < s2.length(); i++){
       			 if(s2[i] != '0'){
          			s2[i]--; // thụt xuống để s2 lên
         		   	s2[0] = '1';
           			 break;
        		}
    		}
		}
		cout <<s2 << " " << s1 ;
	}
}