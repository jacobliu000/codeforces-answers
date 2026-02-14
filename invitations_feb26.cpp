#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, C;

    cin >> N >> C;

    vector<int> F(C, -1);
    vector<int> P(N, -1);
    vector<queue<int>> criteria(C);
    vector<vector<int>> invitee(N);
    for (int i = 0; i < C; i++) {cin >> F[i];}
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        P[i] = x;}


    for (int i = 0; i < N; i++) {
        int num; cin >> num;

        for (int j = 0; j < num; j++) {
            int x; cin >> x; x--;
            criteria[x].push(i);
        }
    }

    //initial

    vector<int> furthest(C, 0);
    vector<int> invited(N, C+1);
    vector<bool> declined(N, false);
    long long ans = 0;
    for (int i = 0; i < C; i++) {
        int num_needed = F[i];
        int cur_invited = 0;
        while (!criteria[i].empty() && cur_invited < num_needed)
        {
            int x = criteria[i].front();
            criteria[i].pop();
            if (invited[x] < i) {continue;}
            invited[x] = i;
            ans += x + 1;

            cur_invited += 1;
        }
    }

    cout << ans << endl;

    for (int i = 0; i < N-1; i++) {

        int d = P[i];

       // cout << "Removing " << d << endl;

        int c = invited[d];
        invited[d] = -1;
        if (c == C+1) { cout << ans << endl; continue; } // ts guy was never invited
        ans -= (d + 1);


           // cout << " Checking the criteria he was invited in (c) " << c << endl;

        while (!criteria[c].empty())
        {
           // cout << " At c = " << c << endl;
            int x = criteria[c].front();
            criteria[c].pop();
            if (invited[x] < c) {continue; }
            
           // cout << " Found x " << x << " which we can switch with " << endl;
            swap(c, invited[x]);
            
            if (c == C+1) {
               // cout << " Reached the end " << endl;
                ans += x + 1;
                break;
            }
        }

        cout << ans << endl;


    }

}