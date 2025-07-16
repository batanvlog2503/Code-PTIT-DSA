#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Kiểm tra tổng có phải số lẻ không
bool isOddSum(int sum) {
    return sum % 2 == 1;
}

// Hàm quay lui để tìm tập con có tổng lẻ
void backtrack(int idx, vector<int> &arr, vector<int> &res, vector<vector<int>> &tmp, int sum) {
    if (idx == arr.size()) {
        if (isOddSum(sum)) {
            tmp.push_back(res);
        }
        return;
    }

    // Chọn phần tử hiện tại
    res.push_back(arr[idx]);
    backtrack(idx + 1, arr, res, tmp, sum + arr[idx]);

    // Không chọn phần tử hiện tại
    res.pop_back();
    backtrack(idx + 1, arr, res, tmp, sum);
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Sắp xếp dãy số theo thứ tự giảm dần
        sort(arr.begin(), arr.end(), greater<int>());

        vector<vector<int>> tmp; // Lưu tập con dạng vector<int>
        vector<int> res;
        
        backtrack(0, arr, res, tmp, 0);

        // Sắp xếp các tập con theo thứ tự từ điển
        sort(tmp.begin(), tmp.end());

        // In kết quả
        for (const auto &vec : tmp) {
            for (size_t i = 0; i < vec.size(); i++) {
                if (i > 0) cout << " ";
                cout << vec[i];
            }
            cout << endl;
        }
    }
    return 0;
}
