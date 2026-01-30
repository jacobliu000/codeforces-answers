#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ops = 0;
    while (c > a || d > b)
    {
        if (c > d) {
            if (c-d < a) {ops = 1; break;}
            ll plus = min( (c-d)/d + 1, (c-a)/d);
            c -= d * plus;
            ops += plus;
        }
        else {
            if (d-c < b) {ops = 1; break;}
            ll plus = min( (d-c)/c + 1, (d-b)/c);
            d -= c * plus;
            ops += plus;        
        }

  //  cout << " c : " << c << " d : " << d << " ops : " << ops <<  endl;
    }

    if (c == a && b == d) {
        cout << ops;
    }
    else cout << -1;


   // cout << " SOLVED ONE ";
    cout << endl;
}
int main() {
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
}