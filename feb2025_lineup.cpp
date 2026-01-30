#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
void solve() {
    int N; cin >> N;
    vector<int> arr(N,-1);
    vector<int> suff(N,-1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }

    //form suffix array
    int cur = arr[N-1];
    vector<pair<int, int>> points;
    points.push_back({-1,N+1});
    points.push_back({N, -1});
    
    for (int i = N-1; i >= 0; i--) {
        if (arr[i] >= cur)
        {
            cur = arr[i];
            points.push_back({i, cur});
        }
        suff[i] = cur;
    }

    sort(points.begin(), points.end());

  //  for (pair<int, int> p : points) {
 //       cout << p.first << "," << p.second << " ";
  //  }
//cout << endl;


    for (int i = 1; i < points.size()-1; i++)
    {
      //  cout << "AT " << i << endl;
        int added = 0;
        vector<pair<int, int>> add;
        int new_suff = points[i+1].second;
        for (int j = points[i].first-1; j >= points[i-1].first+1; j--) {
          //  cout << " Checking out pos " << j << " which is " << arr[j];
            if (arr[j] >= new_suff)
            {
               // cout << " - adding that to the add ";
                new_suff = arr[j];
                add.push_back({j, new_suff});
                added += 1;
            }
           // cout << endl;
        }

       // cout << " ADD ARRAY : ";
      //  for (pair<int, int> a : add) {
      //      cout << a.first << "," << a.second << " ";
      //  }
    //    cout << endl;
        if (!add.empty()) {
                reverse(add.begin(), add.end());

            points.insert(points.begin() + i + 1, add.begin(), add.end());
            break;
        }
    }

    for (int x = 1; x < points.size()-1; x++) {
        cout << points[x].second;
        if (x != points.size()-2) {
            cout << " ";
        }
    }

    cout << endl;

}
int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}