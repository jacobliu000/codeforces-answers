#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    ll N;
    ll def = -1;
    cin >> N;

    vector<vector<vector<ll>>> edges(N); //the edge that a thing is connected to, ZERO INDEXED {p_i, d_i, e_i}
    for (ll i = 2; i <= N; i++) {
        ll p, d, e;
        cin >> p >> d >> e;
        p--;
        edges[p].push_back({i-1, d, e});
    }

    vector<vector<ll>> diff(N, vector<ll>(11, -1));
    vector<ll> enjoyment(N, 0);
    queue<ll> queu;
    queu.push(0);

    while (!queu.empty()) {
        ll cur = queu.front();
        queu.pop();

        for (vector<ll> edge : edges[cur])
        {
            enjoyment[edge[0]] = enjoyment[cur] + edge[2];
            diff[edge[0]] = diff[cur];
            if (edge[1] >= diff[edge[0]][10])
            {
                vector<ll> temp = diff[edge[0]];
                temp.push_back(edge[1]);

                sort(temp.begin(), temp.end(), greater<ll>());

                if (temp.size() > 11) {
                    temp.resize(11);
                }

                diff[edge[0]] = temp;
            }

            queu.push(edge[0]);
        }
    }


    vector<vector<pair<ll, ll>>> sorted_diff(11);

    for (ll i = 0; i < 11; i++) {
        ll pref = -1;
        for (ll j = 0; j < N; j++) {
            
            sorted_diff[i].push_back({diff[j][i], enjoyment[j]});
        }
        sort(sorted_diff[i].begin(), sorted_diff[i].end());

        for (ll j = 0; j < N; j++) {
            pref = max(pref, sorted_diff[i][j].second);

            sorted_diff[i][j].second = pref;
        }
        /*
        cout << "HARDEST DIFFICULTY AT index " << i << " : ";
        for (pair<ll, ll> x : sorted_diff[i]) {
            cout << x.first << " ";
        }
        cout << endl;*/
    }

    ll M;
    cin >> M;

    for (ll i = 0; i < M; i++) {
        ll s, c;
        cin >> s >> c;

        //binary search sorted_diff[c] for s, largest index where its still < s

        ll l = 0;
        ll r = sorted_diff[c].size()-1;

        ll mid = (r + l) / 2;
        ll ans = 0;
        ll mx = -1;

        while (l <= r) {
            mid = (r + l) / 2;

            
            if (sorted_diff[c][mid].first <= s)
            {
                ans = mid;
                mx = max(mx, sorted_diff[c][mid].second);
                l = mid + 1;
            }
            else {
                r = mid-1;
            }

          //  cout << " Visiting " << mid << ", where the enjoyment at " << sorted_diff[c][mid].second << endl;
          //  cout << " Last feasible answer at " << ans << " where the enjoyment at " << sorted_diff[c][ans].second << endl;
        }

        //answer

        cout << mx << endl;


    }

}