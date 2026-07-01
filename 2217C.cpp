#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        if (gcd(a, n) == 1 && gcd(b, m) == 1 && gcd(n, m) <= 2) {
            cout << "YES";
        } else cout << "NO";

        cout << endl;
    }
}