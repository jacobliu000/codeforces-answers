#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define nl '\n'
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c; cin >> t >> c;
    while (t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        vi cnt[2][2];
        FOR(i, 0, n) cnt[a[i] == 'N'][b[i] == 'N'].push_back(i);
        bool ans = count(all(a), 'J') == count(all(b), 'J') 
            and count(all(a), 'N') % 2 == 0 
            and (cnt[0][0].empty() or cnt[1][1].empty() or sz(cnt[0][1]) or sz(cnt[1][0]));
        if (ans) cout << "YES" << nl;
        else cout << "NO" << nl;
        if (!c or !ans) continue;
        vi p;
        if (sz(cnt[0][0]) == n or sz(cnt[1][1]) == n) {
            FOR(i, 0, n) p.push_back(i);
        } else {
            FOR(i, 0, sz(cnt[0][0])) p.push_back(cnt[0][0][i]);
            p.push_back(cnt[0][1].back()); cnt[0][1].pop_back();
            FOR(i, 0, sz(cnt[1][1])) p.push_back(cnt[1][1][i]);
            while (sz(cnt[0][1]) and sz(cnt[1][0])) {
                p.push_back(cnt[1][0].back()); cnt[1][0].pop_back();
                p.push_back(cnt[0][1].back()); cnt[0][1].pop_back();
            }
            p.push_back(cnt[1][0].back());
        }
        FOR(i, 0, n) cout << p[i] + 1 << " \n"[i == n - 1];
        int l = 0;
        cout << "J";
        FOR(i, 1, n) {
            if (a[p[i]] == 'N') l = 1 - l;
            cout << "JN"[l];
        }
        cout << nl;
    }
}