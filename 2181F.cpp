#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        bool all_ones = true;
        int one_counter = 0;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;

            if (a == 1)
            {
                one_counter++;
            }
            else {
                all_ones = false;
            }
        }

        if (all_ones)
        {
            if (one_counter % 2 == 1) {
                cout << "Alice";
            }
            else {
                cout << "Bob";
            }
        }
        else {
            if (one_counter % 2 == 1) cout << "Bob";
            else cout << "Alice";
        }

        cout << endl;
    }
}