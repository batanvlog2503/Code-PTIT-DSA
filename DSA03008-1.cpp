#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        vector<pair<int, int>> v;
        for(int i =0 ;i < n;i++){
            v.push_back({a[i], b[i]});
        }
        int pos = -1, ans = 0, res = 0;
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        });
        for(int i = 0; i < v.size(); i++){
            pair<int, int> p = v[i];

            if(p.first >= pos){
                pos = p.second;
                res++;
                ans = max(ans, res);
            }
        }
        cout << ans << endl;
    }
}