#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int test(int L, int R, vector<int> line, int N) {\

   // cout << "testing " << L << " and " << R << endl;
   vector<bool> contains(N+1,false);

    while (L >= 0 && R < line.size() && line[L] == line[R]) {
     //   cout << " contains " << line[L] << endl;
        contains[line[L]] = true;
        L -= 1;
        R += 1;
    }

    int i = 0;
    while (contains[i] == true) {
        i += 1;
    }
  //cout << " i is " << i << endl;
    return i;

}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr;
        int X = -1;
        int Y = -1;
        for (int i = 0; i < 2*n; i++) {
            int a; cin >> a;
            arr.push_back(a);

            if (a == 0) {
                if (X == -1) X = i;
                else Y = i;
            }
        }

        int ans1 = test(X, X, arr, n);
        int ans2 = test(Y, Y, arr, n);

        int ans3 = -1;
        if ((Y-X) % 2 == 0) ans3 = test((X+Y)/2, (X+Y)/2, arr, n);
        else ans3 = test((X+Y)/2, (X+Y)/2+1, arr, n);

        cout << max(max(ans1, ans2), ans3) << endl;

    
    }
}