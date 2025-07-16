#include <bits/stdc++.h>
using namespace std;

int findMissingIndex(vector<long long>& A, vector<long long>& B, int N) {
    int l = 0, r = N - 2; // B has N-1 elements

    while (l <= r) {
        int m = (l + r) / 2;
        if (A[m] == B[m]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    // Chỉ số bắt đầu từ 1 nên +1
    return l + 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N), B(N - 1);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N - 1; i++) {
            cin >> B[i];
        }

        cout << findMissingIndex(A, B, N) << endl;
    }

    return 0;
}
