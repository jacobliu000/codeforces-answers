#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> dig, vector<int> priority) {
    for (int x : priority) {
        if (dig[x] > 0) {
            return x;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n; 
        cin >> n;

        vector<int> digits(10, 0);
        string s; 
        cin >> s;
        for (char c : s) {
            digits[c - '0'] += 1;
        }

        int ans = 0;

        vector<int> third_dig_p = {5, 4, 3, 2, 1, 0};
        vector<int> sec_dig_p = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        vector<int> fourth_dig_p = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

        while (true) {
            if (digits[0] > 0) {
    
                digits[0] -= 1;



                int third = search(digits, third_dig_p);
                if (third == -1) break;
                digits[third] -= 1;

                int second = search(digits, sec_dig_p);
                if (second == -1) break;
                digits[second] -= 1;

                int fourth = search(digits, fourth_dig_p);
                if (fourth == -1) break;
                digits[fourth] -= 1;
            }

            else if (digits[1] >= 2) {
                digits[1] -= 2;
                int third = search(digits, third_dig_p);
                if (third == -1) break;
                digits[third] -= 1;

                int fourth = search(digits, fourth_dig_p);
                if (fourth == -1) break;
                digits[fourth] -= 1;
            } else {
                break;
            }

            ans += 1;
        }

        cout << ans << "\n";
    }
}