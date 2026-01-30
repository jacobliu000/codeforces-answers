#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        long long s = 0;
        long long mn = 0;
        long long best = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s += x;

            long long cur = (i + 1) * (long long) (i + 2)- s;

            mn = min(mn, cur);

            best = max(best, cur-mn);

        }

        cout << best + s << endl;
    }
}