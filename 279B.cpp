#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, t;

    cin >> n >> t;

    vector<int> books(n,-1);
    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        books[i] = f;
    }

    int ans = -1;
    int l = 0;
    int r = 0;
    int tot = 0;
    while (l < n)
    {
        while (r < n && tot + books[r] <= t)
        {
            tot += books[r];
            r += 1;
            //cout << l << " " << r << " " << tot << endl;
        }

        ans = max(ans, r-l);


        tot -= books[l];
        l += 1;
        //cout << l << " " << r << " " << tot << endl;

    }
    cout << ans;
}