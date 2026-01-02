#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    set<int> vst;
    queue<pair<int, int>> bq;

    bq.push({n, 0});

    while (!bq.empty())
    {
        pair<int,int> cur = bq.front();
        bq.pop();

        int c = cur.first;
        if (c == m) {
            cout << cur.second;
            break;
        }
        if (c < m)
        {
            if (vst.count(2*c) == 0)
            {
                vst.insert(2*c);
                bq.push({c*2,cur.second+1});
            }
        }
        if (c > 0)
        {
            if (vst.count(c-1) == 0)
            {
                vst.insert(c-1);

                bq.push({c-1,cur.second+1});
            }            
        }
    }
}