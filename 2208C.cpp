#include <iostream>
#include <vector>
#include <iomanip> // Required for setprecision
using ll = long long;
using ld = long double;
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N; 
        cin >> N;
        vector<int> points(N, 0);
        vector<ld> cost(N, 0);
        for (int i = 0; i < N; i++) {
            int c, p;
            cin >> c >> p;

            points[i] = c;
            cost[i] = (ld) (100 - p) / 100.0;
        }

        ll running_total = 0;

        vector<ll> points_suf(N+1, 0);
        for (int i = N-1; i >= 0; i--) {
            running_total += points[i];
            points_suf[i] += running_total;
        }

        ld ans = 0;
        for (int i = N-1; i >= 0; i--) {
            if (ans * cost[i] + points[i] > ans) {
                ans *= cost[i];
                ans += points[i];
            }
        }

        cout << fixed << setprecision(10) << ans << "\n";
    }
}