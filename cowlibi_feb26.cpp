#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, C;

    cin >> T >> C;

    while (T--) {
        int N; cin >> N;
        bool ans = true;

        string left; string right; cin >> left >> right;

        vector<vector<int>> cnt(2, vector<int>(2, 0));
        vector<vector<vector<int>>> ex(2, vector<vector<int>>(2));
        for (int i = 0; i < N; i++) {
            char l = left[i];
            char r = right[i];

            cnt[l == 'J'][r == 'J'] += 1;
            ex[l == 'J'][r == 'J'].push_back(i + 1);
        }

        if (cnt[1][0] != cnt[0][1]) {
           // cout << " unequal " << endl;
            ans = false;
        }

        if ((cnt[0][1] + cnt[0][0]) % 2 != 0 || (cnt[1][0] + cnt[0][0]) % 2 != 0) {
           // cout << " even number needed " << endl;
            ans = false;
        }
        if ((cnt[1][0] == 0 && cnt[0][1] == 0) && (cnt[0][0] != 0 && cnt[1][1] != 0)) {
          //  cout << " need connectors " << endl;
            ans = false;
        }

        if (ans) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            continue;
        }


        if (C == 1) {
            string line = "";
            vector<int> perm;
            vector<string> chars = {"N", "J"};
            
            if (cnt[0][0] == N || cnt[1][1] == N) {
                for (int i = 0; i < N; i++) {perm.push_back(i+1);}
            }
            else {
                //get 1, 1 in first
                for (int i = 0; i < cnt[1][1]; i++) {
                    perm.push_back(ex[1][1][i]);
                }
                //then 1 0
                perm.push_back(ex[1][0].back());
                ex[1][0].pop_back();
                for (int i = 0; i < cnt[0][0]; i++) {
                    perm.push_back(ex[0][0][i]);
                }
                while (!ex[0][1].empty() && !ex[1][0].empty()) {
                    perm.push_back(ex[0][1].back());
                    perm.push_back(ex[1][0].back());

                    ex[0][1].pop_back();
                    ex[1][0].pop_back();
                }
                perm.push_back(ex[0][1].back());
            }

            for (int i = 0; i < N; i++) {
                cout << perm[i] << " \n" [i == N-1];
            }
            int cur = 1;
            for (int i = 0; i < N; i++) {
                line += chars[cur];
                if (right[perm[i]-1] == 'N') {cur = 1 - cur;}
            }
            cout << line;
            cout << endl;
        }
    }
}