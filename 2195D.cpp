#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    
    
    while (T--) {
        int n;
        cin >> n;

        vector<ll> func(n,-1);
        vector<ll> arr(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> func[i];
        }

        for (int i = 1; i < n-1; i++) {
            ll ans = (func[i+1] - 2 * func[i] + func[i-1])/2;

           // cout << " arr[" << i <<"] is just (" << func[i+1] << " - 2 * " << func[i] << " + " << func[i-1] << ")/2 which is just " << ans << endl; 
            arr[i] = ans;
        }


        ll tot = 0;
        //find a_n 
        for (int i = 1; i < n-1; i++) {
            tot += i * arr[i];
        }
        arr[n-1] = (func[0] - tot)/(n-1);
       // cout << " since f(1) = func[0] = " << func[0] << " and 1 * a_2 + 2 * a_3 ... is " << tot << " then that means a_n is " << arr[n-1] << endl;

        tot = 0;
        for (int i = 1; i < n-1; i++) {
            tot += (n - 1 - i) * arr[i];
        }

        arr[0] = (func[n-1] - tot)/(n-1);
     //   cout << " since f(n) = func[n-1] = " << func[n-1] << " and tot. is " << tot << " then that means a_1 is " << arr[0] << endl;

        for (ll a : arr) {
            cout << a << " ";
        }
        cout << "\n";
    }
}