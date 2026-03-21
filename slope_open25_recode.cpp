#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;

    vector<ll> enjoyment(N+1, 0);
    vector<ll> difficulty(N+1, 0);
    vector<ll> parent(N+1, 0);
    vector<vector<ll>> child(N+1);
    for (int i = 2; i <= N; i++) {
        cin >> parent[i] >> difficulty[i] >> enjoyment[i];
        child[parent[i]].push_back(i);
    }

    int M; cin >> M;
    vector<pair<ll, ll>> queries;

    for (int i = 0; i < M; i++) {
        ll s, c;
        cin >> s >> c;
        queries.push_back({s, c});
    }

    vector<vector<ll>> top(11, vector<ll>(N+1, 0));

    queue<ll> bfs;
    bfs.push(1);

    while (!bfs.empty()) {
        ll cur = bfs.front();
        bfs.pop();
        for (ll c : child[cur]) {
            bfs.push(c);

            enjoyment[c] = enjoyment[c] + enjoyment[cur];
            ll d = difficulty[c];

            // add {d, e} into top[1-11][c]

            vector<ll> toplist;

            for (int i = 0; i < 11; i++) {
                toplist.push_back(top[i][cur]);
            }
            if (d >= top[10][cur]) {
                toplist.push_back(d);
            }
            sort(toplist.begin(), toplist.end());
            reverse(toplist.begin(), toplist.end());
        for (int i = 0; i < 11; i++) {
        
            top[i][c] = toplist[i];
            }
            

        }
    }



    vector<vector<pair<ll,ll>>> search(11, vector<pair<ll, ll>>(N+1));

    for (int i = 0; i < 11; i++) {
        ll mx = -1;
        for (int j = 1; j <= N; j++) {
            search[i][j] = {top[i][j], enjoyment[j]};

        }
        sort(search[i].begin(), search[i].end());
        
        for (int j = 1; j <= N; j++) {

            search[i][j].second = max(mx, search[i][j].second);
          mx = search[i][j].second;
        //              cout << search[i][j].first << "," << search[i][j].second << " ";

        }
    
    }



    for (pair<ll,ll> q : queries) {
        ll s = q.first;
        ll c = q.second;

     //   cout << " query is " << s << " , " << c << endl;

        int index = upper_bound(search[c].begin(), search[c].end(), make_pair((long long)s, (long long)1e18)) - search[c].begin() -1;

 //       cout << "index is " << index << endl;


        if (index < 0) cout << 0 << endl;
        else cout << search[c][index].second << endl;

    }

}