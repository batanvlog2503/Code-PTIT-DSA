#include <iostream>
#include <string>

using namespace std;

int findLongestValidParentheses(string s) {
    int max_length = 0;
    int left = 0, right = 0;

    // Duyệt từ trái sang phải
    for (char c : s) {
        if (c == '(') left++;
        else right++;

        if (left == right) {
            max_length = max(max_length, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }

    left = right = 0; // Reset bộ đếm

    // Duyệt từ phải sang trái
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')') right++;
        else left++;

        if (left == right) {
            max_length = max(max_length, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }

    return max_length;
}

int main() {
    int q;
    cin >> q;
    cin.ignore();
    while (q--) {
        string s;
        cin >> s;
        cout << findLongestValidParentheses(s) << endl;
    }
    return 0;
}
