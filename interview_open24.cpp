#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using ll = long long;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> T;

    for (int i = 0; i < K; i++) {
        pq.push(0);
    }
    map<ll, vector<ll>> edges;

    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        T.push_back(x);

        ll front = pq.top();
      //  cout << " At x= " << x << " and front = " << front << endl;
        pq.pop();
        pq.push(front + x);

        edges[front + x];
        edges[front + x].push_back(front);

    }

    ll start = pq.top();
    queue<ll> q;
    q.push(start);

    set<ll> vst;
    vst.insert(start);
    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        if (!vst.count(cur)) continue;
    //    cout << "traversing " << cur << endl;
        for (ll e : edges[cur]) {
           // cout << "- edges to " << e << endl;
            if (!vst.count(e)) {
                q.push(e);
                vst.insert(e);
            }
        }
    }   

    cout << start << endl;
    for (int i = 0; i < K; i++) {
        if (vst.count(T[i])) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }

}