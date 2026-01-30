#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long T;
    cin >> T;

    vector<long long> answer(T,0);

    for (int j = 0; j < T; j++)
    {
        long long n, k;

        cin >> n >> k;

        vector<long long> q(n,0);
        vector<long long> r(n,0);
        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
        }

        sort(q.begin(), q.end());
        sort(r.begin(), r.end());

        long long ans = 0;

        long long left = 0;
        long long right = n;

        while (left <= right)
        {
            long long mid = (right + left)/2;
            //cout << "trying " << mid << endl;

            bool works = true;
            for (int i = 0; i < mid; i++)
            {
                long long cur_r = r[mid-i-1];
                long long cur_q = q[i];

                if (cur_r <= (k - cur_q) / (cur_q + 1))
                {
                    continue;
                }
                else {
                    //cout << "doesnt work r = " << cur_r << " q = " << cur_q << endl;
                    works = false;
                    break;
                }
            }

            if (works)
            {
                ans = mid;
                left = mid+1;
            }
            else {
                right = mid-1;
            }

            
        }

        answer[j] = ans; 



    }

    for (long long t : answer)
    {
        cout << t << endl;
    }
}