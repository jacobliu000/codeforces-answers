#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N, P;

    vector<pair<ll, ll>> posts;  //mapped to original order
    vector<pair<ll, ll>> fence;
    vector<map<ll, vector<ll>>> edges(2); // 0 => shared x, 1 => shared y
    cin >> N >> P;
    for (int i = 0; i < P; i++) {
        ll x, y; cin >> x >> y;
        posts.push_back({x, y});

        edges[0][x];
        edges[0][x].push_back(y); 


        edges[1][y];
        edges[1][y].push_back(x); 
    }

    //start at 0
    queue<pair<ll,ll>> q;
    set<pair<ll, ll>> vst;
    map<pair<ll, ll>, pair<ll, ll>> parent;
    vst.insert(posts[0]);
    q.push({posts[0]});
    
    pair<ll, ll> last;
    
    while (!q.empty()) {
        pair<ll, ll> cur = q.front();
        q.pop();
      //  cout << " At " << cur.first << ", " << cur.second << endl;
        last = cur;


        ll cur_x = cur.first;
        ll cur_y = cur.second;

        bool found = false;
        for (ll e : edges[0][cur_x])
        {
            pair<ll,ll> nxt = {cur_x, e};
            if (!vst.count(nxt)) {
              //  cout << " - can go to " << nxt.first << " " << nxt.second << endl;
                parent[nxt] = cur;
                q.push(nxt);
                vst.insert(nxt);
                found = true;
                break;
            }
        }

        if (found) continue;
        for (ll e : edges[1][cur_y])
        {
            pair<ll,ll> nxt = {e, cur_y};
            if (!vst.count(nxt)) {
            //    cout << " - can go to " << nxt.first << " " << nxt.second << endl;

                parent[nxt] = cur;
                q.push(nxt);
                vst.insert(nxt);
                break;
            }
        }
    }

    //start from last
    for (int i = 0; i < P; i++) {
        fence.push_back(last);
        last = parent[last];
    }
    reverse(fence.begin(), fence.end());

    for (int i = 0; i < P; i++) {
        fence.push_back(fence[i]);
    }
    fence.push_back(fence[0]);

    for (pair<ll, ll> f : fence) {
        cout << f.first << ", " << f.second << endl;
    }


    vector<ll> pref;
    ll tot = 0;
    for (int i = 0; i < 2 * P; i++) {
        pref.push_back(tot);
        if (i != 2 * P -1) {
            tot += abs(fence[i+1].first - fence[i].first) + abs(fence[i+1].second - fence[i].second);
        }
    }


    cout << endl;

    vector<ll> ans(P+1, 0);
    for (int z = 0; z < N; z++) {
        cout << " starting query " << z << endl;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll s = -1;
        ll sn = -1;
        ll e;
        ll en;
        //find first one
        for (int i = 0; i < P; i++) {
            if (x1 == fence[i].first && y1 == fence[i].second) {
                s = i;
                sn = 0;
                break;
            }

            ll bx = max(fence[i+1].first, fence[i].first);
            ll by = max(fence[i+1].second, fence[i].second);
            ll sx = min(fence[i+1].first, fence[i].first);
            ll sy = min(fence[i+1].second, fence[i].second);

        //    cout << " checking from " << sx << " " << sy << " to " << bx << " " << by << endl;
            
            if (x1 <= bx && x1 >= sx && y1 <= by && y1 >= sy) {
                s = i + 1;
                sn = abs(fence[s].first - x1 + fence[s].second - y1);

              //  cout << " FOUND s = " << s << " and sn " << sn << endl;
                break;
            }
        }

        for (int i = s; i < 2 * P; i++) {
            if (x2 == fence[i].first && y2 == fence[i].second) {
                e = i;
                en = 0;
                break;
            }


            ll bx = max(fence[i+1].first, fence[i].first);
            ll by = max(fence[i+1].second, fence[i].second);
            ll sx = min(fence[i+1].first, fence[i].first);
            ll sy = min(fence[i+1].second, fence[i].second);

           cout << " checking from " << sx << " " << sy << " to " << bx << " " << by << endl;
            
            if (x2 <= bx && x2 >= sx && y2 <= by && y2 >= sy) {
                e = i + 1;
                en = abs(fence[e].first - x2 + fence[e].second - y2);
                break;
            }
        }
                cout << "query " << z << " s = " << s << " sn = " << sn << " e = " << e << " en = " << en << endl;

        ll p1, p2;

       ll dist = pref[e] - pref[s] + sn - en;
   //     cout << " original travels " << dist << endl;
       // cout << " otras way travels " << (pref.back()-pref[0])/2 - dist << endl;
       if (s%P != e%P) {
        if ((pref.back()-pref[0])/2 - dist < dist) {
            cout << " other way! " << endl;
            //must contain end, might contain start
            p1 = e;
            if (sn==0) p2=s;
            else p2=s-1;
        }else {
            //must contain start, might not contain end
            p1 = s;
            if (en==0) p2 = e;
            else p2 = e-1;
        }


        p1 %= P;
        p2 %= P;


        ans[min(p1, p2)] += 1;
        ans[(max(p1, p2)+1)] -= 1;
        cout << "-  goes from " << min(p1, p2) << " to " << (max(p1, p2)+1)<< endl;

    }





    }

    tot = 0;
    for (int i = 0; i < P; i++) {
        tot += ans[i];
        cout << tot << endl;
    }
}