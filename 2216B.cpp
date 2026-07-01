#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int T; 
    cin >> T;
    
    while (T--) {
        ll ans = 0;
        ll C_t, C_h, C_u;
        cin >> C_t >> C_h >> C_u;

        ll shared_tu = min(C_t, C_u);
        ans += 4 * shared_tu;

       // cout << " ans from shared_tu " << ans << " shared_tu = " << shared_tu << endl;
        C_t -= shared_tu;
        C_u -= shared_tu;



        ll shared_th = min(C_t / 2, C_h);

        ans += 7 * shared_th;
        C_t -= shared_th * 2;
        C_h -= shared_th;

       // cout << "C_t = " << C_t << " and C_h is " << C_h << endl;

       // cout << " ans is " << ans << endl;

        if (C_t == 1 && C_h >= 1) {
            ans += 5;
            C_t = 0;
            C_h -= 1;
        }

      //  cout << " ans is " << ans << endl;

        if (C_t != 0) {
            ans += 1 + 2 * C_t;
        }

      //  cout << " ans is " << ans << endl;

        ans += 3 * C_h;
        ans += 3 * C_u;

       // cout << "ans after adding everything else ";

        cout << ans << endl;
    }
}