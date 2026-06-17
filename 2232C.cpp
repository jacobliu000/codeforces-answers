#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> l, int a, int tables, int seats) {
    int a_passed = 0;
    int open_slots = 0;
    int tables_filled = 0;
    int ans = 0;
    for (int i = 0; i < l.size(); i++) {
        int cur = l[i];
        if (cur == 0) {
            if (a_passed < a) cur = -1;
            else cur = 1;

            a_passed += 1;
        }

        if (cur == -1) {
            if (tables_filled < tables) {
                tables_filled += 1;
                open_slots += (seats-1);
                ans += 1;
            }
        } else {
            if (open_slots > 0) 
            {
                open_slots -= 1;
                ans += 1;
            }
        }
    }

    return ans;
}
int main() {
    int T; cin >> T;

    while (T--) {
        vector<int> line;
        vector<int> groups;
        int n, x, s;
        cin >> n >> x >> s;


        int ambiverts = 0;
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            if (c == 'I') 
            {
                line.push_back(-1);
            }
            if (c == 'A') {
                ambiverts += 1;
                line.push_back(0);

            }
            if (c == 'E') {
                line.push_back(1);
            }
        }

        int ans = -1;
        for (int i = 0; i <= ambiverts; i++) {
            ans = max(ans, solve(line, i, x, s));
        }
        cout << ans << endl;

    }



}