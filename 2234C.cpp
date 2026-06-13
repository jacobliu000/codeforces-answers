#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> heights(n);

        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        for (int start = 0; start < n; start++) {
            //forwards loop
            ll current_water = 0;
            vector<ll> ans(n, 0);
            for (int i = start; i < start + n - 1; i++) {
                ll cur = i % n;
                ll next_height = heights[cur];
                if (next_height > current_water) {
                    ans[(cur + 1) % n] = next_height;
                    current_water = next_height;
                } 
                else {
                    ans[(cur + 1) % n] = current_water;
                }
            }

            current_water = 0;
            for (int i = start-1; i > start-n; i--) {
                ll cur = (n + n + i) % n;
                ll next_height = heights[cur];
                if (next_height > current_water) {
                    ans[(cur) % n] = min(ans[(cur)%n], next_height);
                    current_water = next_height;
                } 
                else {
                    ans[(cur) % n] = min(ans[(cur)%n], current_water);
                }
                //cout << " compared with height index " << cur << " which is " << next_height << " and got the value " << current_water << endl;

            }

            ll tot = 0;
            for (int i = 0; i < n; i++) {
               // cout << i << " is " << ans[i] << endl;
                tot += ans[i];
            }
            cout << tot << " ";
            
        }
        cout << endl;

    
    }
}