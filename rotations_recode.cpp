#include <iostream>
#include <vector>


using namespace std;

int main() {
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        arr.push_back(arr[i]);
    }
    vector<int> ans(N, 3 * N);

    int r = 0;
    vector<int> last(N, -1);
    vector<int> next(N, -1);
    for (int i = 0; i < 2 * N; i++) {
        int cur = arr[i];
        if (last[cur] == -1) {
            r = max(r, i);
        }
        else {
            if (last[cur] < N) next[last[cur]] = i;
        }
        last[cur] = i;
    }

    for (int l = 0; l < N; l++) {
        ans[l] = min(ans[l], r - l);
        ans[r % N] = min(ans[r % N], r - l);

        r = max(r, next[l]);
    }

    for (int i = 0; i <= 2*N-1; i++) {
        ans[(i+1) % N] = min(ans[i % N] + 1, ans[(i+1)%N]);
    }
    for (int i = 2*N-1; i >= 0; i--) {
        ans[i % N] = min(ans[(i+1) % N] + 1, ans[i % N]);
   }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N-1];
    }
}