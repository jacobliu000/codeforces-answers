#include <iostream>

using namespace std;
using ll = long long;
int main() {
    int T; 
    cin >> T;

    while (T--) {
        ll p, q;
        cin >> p >> q;

        if (p < q && 2*(q-p) <= p && 3 * (q-p) <= q) {
            cout << "Bob";
        } else {
            cout << "Alice";
        }
        cout << "\n";
    }
}