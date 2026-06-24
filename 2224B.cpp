#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int T; cin >> T;

    while (T--) {
        int n;
        cin >> n;

        ll max_v = -1;
        ll mex_v = 0;
        ll ans = 0;

        vector<int> nums;

        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            max_v = max(max_v, a);
            nums.push_back(a);
            
        }

        sort(nums.begin(), nums.end());

        /*
        
        for (int x : nums) cout << x << " ";
        cout << endl;
        */
        //find the highest mex
        int i = 0;
        while (nums[i] == mex_v) {
            mex_v += 1;
            i += 1;
        }

        ans += max_v * n;
       // cout << " max values gives " << ans << endl;

        nums.pop_back();

        ll cur_mex = 0;
        if (max_v == 0) cur_mex = 1;
        ans += cur_mex;
        ll extras = 0;
        for (int x : nums) {
            if (x == cur_mex - 1) {
                extras += 1;
                continue;
            }

            if (x == cur_mex) cur_mex += 1;
            if (cur_mex == max_v) cur_mex += 1;
            ans += cur_mex;

      //      cout << " At the number " << x << " and cur_mex is " << cur_mex << " and ans is " << ans << endl;
        }
        ans += cur_mex * extras;
        cout << ans << endl;
}
}


//20 2 12 3 5 14 0 7 11 0 11 4 6 14 8 2 13 9 1 10 2
