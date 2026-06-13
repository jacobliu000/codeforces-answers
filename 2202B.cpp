#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;

    while (T--) {
        int n;
        string s;


        cin >> n;
        cin >> s;

        bool ans = true;

        if (n % 2 == 1) {
            if (s[0] != 'a' && s[0] != '?')
            {
                cout << "NO" << endl;
                continue;
            }
        }

        int start = n % 2;
        for (int i = start; i < n-1; i+=2) {
            if (s[i] == '?' || s[i+1] == '?') {
                continue;
            }
            if (s[i] == s[i+1]) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "YES";
        else cout << "NO";

        cout << endl;
    }
}