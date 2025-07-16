#include<bits/stdc++.h>

using namespace std;
int main(){
	#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countIntersections(const string& s) {
    vector<int> pos[26];  
   
    for (int i = 0; i < 52; i++) {
        pos[s[i] - 'A'].push_back(i);
    }

    int count = 0;  

    
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            int x1 = pos[i][0], x2 = pos[i][1]; 
            int y1 = pos[j][0], y2 = pos[j][1];  

            
            if ((x1 < y1 && y1 < x2 && x2 < y2) || (y1 < x1 && x1 < y2 && y2 < x2)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s; 
    
    cout << countIntersections(s) << endl;  
    return 0;
}

}