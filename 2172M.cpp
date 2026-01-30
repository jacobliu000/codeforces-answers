#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cities(n,-1);
    vector<vector<int>> edges(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        cin >> cities[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<pair<int, int>> BFS;
    BFS.push({0, 0});

    vector<int> ans(k,-1);
    vector<bool> vst(n,false);
    vst[0] = true;

    while (!BFS.empty())
    {
        pair<int, int> cur = BFS.front();
        BFS.pop();


        int curCity = cur.first;
        int curDist = cur.second;
        int curProd = cities[curCity];
      //  cout << " Visiting city " << curCity+1 << " which is " << curDist << " away and has product " << curProd << endl;

        ans[curProd-1] = max(ans[curProd-1], curDist);

        for (int x : edges[curCity])
        {
            if (!vst[x])
            {
                BFS.push({x, curDist+1});
                vst[x] = true;
            }
        }
    }

    for (int a : ans)
    {
        cout << a << " ";
    }
}