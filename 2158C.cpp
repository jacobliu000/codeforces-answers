#include <iostream>
#include <vector>

using namespace std;


int main() {
    long long T;

    cin >> T;

    while (T--) {
        long long n, k;

        cin >> n >> k;

        vector<long long> sums(n,0);
        vector<long long> add(n,0);
        long long tot = 0;
        for (int i = 0; i < n; i++)
        {
            
            long long a;
            cin >> a;

            tot += a;
            sums[i] = tot;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> add[i];
        }


        cout << endl;
        vector<long long> pref(n,0);
        vector<long long> suf(n, 0);

        long long minPref = 0;//sums[0];
        long long maxSuf = sums[n-1];
        for (int i = 0; i < n; i++)
        {   
            minPref = min(minPref, sums[i]);
            pref[i] = minPref;

        }


        for (int i = n-1; i >= 0; i--)
        {   
            maxSuf = max(maxSuf, sums[i]);
            suf[i] = maxSuf;
        }

/*/
        for (int s : sums)
        {
            cout << s << " ";
        }

        cout << endl;
        for (int s : suf)
        {
            cout << s << " ";
        }
        cout << endl;
*/
        

            long long ans = -1;
            for (int i = 0; i < n; i++)
            {
                long long poss;
                if (i==0)
                {
                    poss = suf[i];
                }
                else {
                    poss = suf[i] - pref[i-1];

                }
                if (k % 2 == 1)
                {
                    poss += add[i];
                }

                if (i == 0) {ans = poss;}
                ans = max(ans, poss);
            }

            cout << ans;
        
    }
}