#include <iostream>
#include <vector>


using namespace std;
using ll = long long;
int main() {
    int T; cin >> T;
    while (T--) {
        ll non_unique = 0;
        int n; cin >> n;
        vector<int> cards(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> cards[i];
            if (cards[i]>1) non_unique += 1;
        }

        ll ans = 0;
        ll unique_placed = 0;
        for (int i = 1; i <= n; i++) {
            if (cards[i] != 1) {
                if (non_unique == 1) unique_placed += (cards[i] / 2);
                else unique_placed += (cards[i] / 2) - 1;
                ans += cards[i];
            }
        }

        ll unique = n - non_unique;
        ans += min(unique, unique_placed);

        if (ans < 3) ans = 0;
        cout << ans << endl;

    }

}