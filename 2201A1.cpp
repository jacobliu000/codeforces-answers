#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> arr(N,-1);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int ans = 1;
        int cur_start = arr[0];
        int cur_end = arr[0];
        for (int i = 1; i < N; i++) {
            if (arr[i] >= cur_start + 1 && arr[i] <= cur_end + 1) {
                cur_end = arr[i];
            }
            else {
                ans += 1;
                cur_start = arr[i];
                cur_end = arr[i];
            }
        }

        cout << ans << endl;
    }
}