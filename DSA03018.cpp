#include<bits/stdc++.h>

using namespace std;

long long reverse_number(long long n){
	long long sum = 0;
	while(n){
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	return sum;
}
string lucky_number1(long long n){
	if(n < 4){
		return "-1";
	}
	if(n == 4){
		return "4";
	}
	if(n == 7){
		return "7";
		
	}
	if(n > 4 && n < 7){
		return "-1";
	}
	string tmp = "";
	
	while(n > 0){
		
		if(n < 4 && n > 0){
			return "-1";
		}
		if(n > 4 && n < 7){
			return "-1";
		}
		while(n >= 4){
			tmp += '4';
			n-= 4;
			
		}
		
	}
	return tmp;
}

bool cmp(string a, string b){
	if(a.length() == b.length()){
		return a > b;
	}
	return a > b;
}
string lucky_number2(long long n){
	if(n < 4){
		return "-1";
	}
	if(n == 4){
		return "4";
	}
	if(n == 7){
		return "7";
		
	}
	if(n > 4 && n < 7){
		return "-1";
	}
	string tmp = "";
	
	while(n > 0){
		
		if(n < 4 && n > 0){
			return "-1";
		}
		if(n > 4 && n < 7){
			return "-1";
		}
		while(n >= 7){
			tmp += '7';
			n -= 7;
		}
		while(n >= 4){
			tmp += '4';
			n-=4;
		}
		
	}
	return tmp;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		long long n;
		cin >> n;
		string s1 = lucky_number1(n);
		string s2 = lucky_number2(n);	
		reverse(s2.begin(), s2.end());
		cout <<s1 << endl <<s2;
		
	}
}