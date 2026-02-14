#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> arr;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        a = a % M;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++) {
        arr.push_back(M + arr[i]);
    }

    vector<ll> pref;
    pref.push_back(0);
    ll pref_tot = 0;
    for (int i = 0; i < arr.size(); i++) {
        pref.push_back(pref_tot + arr[i]);
        pref_tot += arr[i];
    }
    //for (ll a : arr) { cout << a << " ";} cout << endl;
    //for (ll p : pref) {cout << p << " ";}
    //cout << endl;

    ll L = 0;
    ll R = N-1;

    ll min_sol = M * N + 1;
    while (R < 2 * N)
    {
        ll mid = (R+L)/2;

        if (N % 2 == 1) {
            ll tot = pref[R+1]-pref[mid+1] - (pref[mid]-pref[L]);//sum(mid+1, R) - sum(L, mid-1);
            //cout << "pref[L] = " << pref[L] << endl;
            min_sol = min(tot, min_sol);

            //cout << " L = " << L << " R = " << R << " and tot = " << tot << endl;
        }
        else {
            ll tot = pref[R+1]-pref[mid+1] - (pref[mid+1]-pref[L]);
            min_sol = min(tot, min_sol);
        }
        L++; R++;
    }

    cout << min_sol;
}
int main() {
    ll T; cin >> T;
    while (T--) 
    {
        solve();
        cout << endl;
    }
}