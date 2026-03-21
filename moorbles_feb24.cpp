#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T; cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<int> left(M, 0);
        vector<int> right(M, 0);

        for (int i = 0; i < M; i++) {
            int min_e = 1001;
            int max_e = -1;
            int min_o = 1001;
            int max_o = -1;
            for (int j = 0; j < K; j++) {
                int a; cin >> a;
                if (a % 2 == 0) {
                    min_e = min(a, min_e);
                    max_e = max(a, max_e);
                } else {
                    min_o = min(a, min_o);
                    max_o = max(a, max_o);
                }
            }

            left[i] = min(-max_o, min_e);
            right[i] = min(-max_e, min_o);
        }

        int lost = 0;
        for (int i = 0; i < M; i++) {
            lost += left[i];
        }
        for (int i = M-1; i >= 0; i--) {
            if (N + lost > 0) {
                break;
            } else {
                if (right[i] > left[i]) {
                    lost += right[i];
                    lost -= left[i];
                }
            }
        }
    }
}