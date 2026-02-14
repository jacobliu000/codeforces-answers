#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    int large = 3 * N;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        arr.push_back(A);
    }

    for (int i = 0; i < N; i++) {
        arr.push_back(arr[i]);
    }

    vector<int> last(N+1, -1);
    vector<int> next(N, -1);
    vector<int> ans(N, large);

    int R = 0;
    for (int i = 0; i < 2 * N; i++) {
        int cur = arr[i];
        if (last[cur] == -1) {
            R = max(R, i);
        }
        else if (last[cur] < N) {
            next[last[cur]] = i;
        }
        last[cur] = i;
    }




    for (int L = 0; L < N; L++){
        ans[L] = min(ans[L], (R - L));
        ans[R % N] = min(ans[R % N], (R-L));

      //  cout << L << " " << R << endl;

        if (next[L] != -1) {
        R = max(R, next[L]);
        }
    }

    for (int x = 0; x < 2; x++) {
    for (int i = 0; i < N; i++) {
        ans[(i+1) % N] = min(ans[(i+1) % N], ans[i]+1);
    }
    for (int i = N-1; i >= 0; i--) {
        ans[i] = min(ans[(i+1) % N] + 1, ans[i]);
    }
    }


    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if (i != N-1) {
            cout << " ";
        }
    }
    //0 1 2 3 4 5 6 7 8 9 0 1
    //1 2 3 1 3 4 1 2 3 1 3 4
}