#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    

    while (T--) {
        int n; cin >> n;
        vector<int> arr(n,0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
       } 
       int trash;
       for (int i = 0; i < n; i++) cin >> trash;

       int ans = 0;

       for (int i = 0; i < n; i++) {
        int change = -1;
        if (i == 0) {
            change = gcd(arr[i], arr[i+1]);
        }
        else if (i == n-1) {
            change = gcd(arr[i], arr[i-1]);
        }
        else {
            change = lcm(gcd(arr[i],arr[i+1]), gcd(arr[i],arr[i-1]));
        }

        if (change != arr[i]) {
            ans += 1;
            arr[i] = change;
        }
       
    }
        cout << ans << endl;
    }
}