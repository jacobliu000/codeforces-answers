#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T; cin >> T;

    while (T--) {
        int ans = -1;
        int n; cin >> n;
        vector<int> arr(n,0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                ans = max(ans, arr[i] ^ arr[j]);
            }   
        }

        cout << ans << endl;
    }
}