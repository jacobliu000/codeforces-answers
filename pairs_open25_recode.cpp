#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using ll = long long;
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    map<ll, ll> cows;
    map<ll, set<ll>> edges;
    set<ll> ids;
    set<ll> vst;

    queue<ll> leaves;

    for (int i = 0; i < N; i++) {
        ll n_i, d_i;
        cin >> n_i >> d_i;
        cows[d_i] = n_i;
        ids.insert(d_i);
    }

    for (ll i : ids) {
        if (cows.count(A-i)) {
            edges[i].insert(A-i);
        }
        if (cows.count(B-i)) {
            edges[i].insert(B-i);
        }

        if (edges[i].size() == 1) {
            leaves.push(i);
        }
    }

    ll ans = 0;

    while (!leaves.empty()) {
        ll cur = leaves.front();
        leaves.pop();

       // cout << " visiting " << cur << " which has " << edges[cur].size() << " edges now " << endl;

        if (edges[cur].size() == 0) continue;

        ll edge = *edges[cur].begin();
        //cout << "-  checking with edge " << edge << endl;

        if (edge == cur) {
            ans += cows[edge] / 2;
        }
        else {
            ans += min(cows[cur], cows[edge]);
           // cout << " - ans = " << ans << " after addding " << min(cows[cur], cows[edge]) << endl;

            cows[edge] -= min(cows[cur], cows[edge]);

            edges[edge].erase(cur);

            if (edges[edge].size() == 1) {
              //  cout << " - adding " << edge << " to queue " << endl;
                leaves.push(edge);
            }
    }

    }
    cout << ans;
}