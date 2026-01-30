#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


using ll = long long;

ll full() {
    ll N, M;
    ll solution = 0;
    cin >> N >> M;

    vector<ll> left(N,-1);
    vector<ll> right(N,-1);

    // {destination, sum}
    vector<vector<pair<ll, ll>>> edges(N, vector<pair<ll, ll>>());
    for (ll i = 0; i < N; i++) {cin >> left[i];}
    for (ll i = 0; i < N; i++) {cin >> right[i];}

    //gets edges
    for (ll i = 0; i < M; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
         
        x -= 1;
        y -= 1;

        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }

    //dfs
    vector<bool> vst(N,false);
    vector<ll> coef(N, 1);
    vector<ll> cons(N, 1);

    for (ll i = 0; i < N; i++) {
        if (!vst[i])
        {

            ll A;
            vector<ll> ts_time_vst;
            coef[i] = 1;
            cons[i] = 0;

            queue<ll> BFS;

            BFS.push(i);
            vst[i] = true;

            bool was_fixed = false;
            while (!BFS.empty())
            {
                ll cur = BFS.front();
                ts_time_vst.push_back(cur);
                BFS.pop();
            

                for (pair<ll, ll> e : edges[cur])
                {
                    ll dest = e.first;
                    ll sum = e.second;

                    if (vst[dest]) {
                        //check for accuracy
                        ll new_cons;
                        ll new_coef;

                        new_cons = sum - cons[cur];
                        new_coef = -coef[cur];

                        if (new_coef == coef[dest])
                        {
                            if (new_cons != cons[dest])
                            {
                                return -1;
                            }
                        }
                        else {
                            if ((new_cons - cons[dest]) % 2 == 1)
                            {
                                return -1;
                            }
                            else {
                                if (!was_fixed) {
                                    A = -(new_cons-cons[dest])/(2 * new_coef);
                                    was_fixed = true;
                                }
                                else {
                                    if (A != -(new_cons-cons[dest])/(2 * new_coef)){
                                    return -1;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        coef[dest] = -coef[cur];
                        cons[dest] = sum - cons[cur];
                        vst[dest] = true;
                        BFS.push(dest);
                    }

                }
                
                //


           
            }

            if (was_fixed) {
                for (ll x : ts_time_vst)
                {
                    if (coef[x] * A + cons[x] >= left[x] && coef[x] * A + cons[x] <= right[x])
                    {
                        solution += 1;
                    }
                }
            }

            else {
                vector<pair<ll, ll>> events;
                for (ll x : ts_time_vst)
                {
                    if (coef[x] == 1) {
                        events.push_back({left[x] - cons[x], 1});
                        events.push_back({right[x] - cons[x] + 1, -1});
                    }
                    else {
                        events.push_back({cons[x] - right[x], 1});
                        events.push_back({cons[x] - left[x] + 1, -1});

                    }
                }

                sort(events.begin(), events.end());
                ll total = 0;
                ll maxAns = 0;
                for (pair<ll, ll> e : events)
                {
                    total += e.second;
                    maxAns = max(total, maxAns);
                }
                solution += maxAns;
            }

        }
    }

    return solution;
}
int main() {
    ll T;
    cin >> T;


    while (T--) {
        cout << full() << endl;
    }
}
