#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> F(C, 0);
    vector<int> P(N, 0);
    for (int i = 0; i < C; i++) {cin >> F[i];}
    for (int i = 0; i < N; i++) {cin >> P[i];}

    vector<queue<int>> criteria(C);

    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int a; cin >> a; a -= 1;

            criteria[a].push(i);
        }
    }
    vector<int> inv(N, C+1);
    long long ans = 0;
    //get first number
    for (int i = 0; i < C; i++) {
        int need = F[i];
        int found = 0;
        while (!criteria[i].empty() && found < need) {
            int next = criteria[i].front();
            criteria[i].pop();
            if (inv[next] < i) {continue;}

            inv[next] = i;
            found += 1;
            ans += next + 1;
        }
    }
    cout << ans << endl;

    for (int i = 0; i < N-1; i++) {
        int rm = P[i];
        rm -= 1;

        int check = inv[rm]; //the criteria which rm was at
        inv[rm] = -1;
        if (check == C + 1) {
            cout << ans << endl;
            continue;
        }
        
        ans -= (rm + 1);

        while (!criteria[check].empty()) {
            int next = criteria[check].front();
            criteria[check].pop();

            if (inv[next] < check) {continue;}
            if (inv[next] == C + 1) {
                //never invited before
                inv[next] = check;
                ans += next + 1;
                break;
            }
            else {
                swap(check, inv[next]);
            }
        }

        cout << ans << endl;
    }
}