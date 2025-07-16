#include <bits/stdc++.h>
using namespace std;
int a[100000];
void check() {
    int n, k;
    cin >> n >> k;
  
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
  sort(a, a +n);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += lower_bound(a + i + 1, a + n, a[i] + k) - (a + i + 1);
    }
    cout << res;
}

int main() {
    
   int q;
   cin >> q;
   
    while (q--) {
        check();
        cout << endl;
        memset(a, 0, sizeof(a));
    }
    return 0;
}