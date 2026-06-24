#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;
        int cur_length = 1;
        int max_length = -1;
        int cur_item; cin >> cur_item;
        for (int i = 1; i < N; i++) {
            int a; cin >> a;
            if (a == cur_item) cur_length += 1;
            else {
                cur_item = a;
                max_length = max(max_length, cur_length);
                cur_length = 1;
            }
        }

        max_length = max(max_length, cur_length);

        if (max_length >= M) cout << "NO";
        else cout << "YES";

        cout << endl;
    }
}