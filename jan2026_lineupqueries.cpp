#include <iostream>

using namespace std;

long long findcow(long long c, long long t) {
    if (t < 2 * c) {
       // cout << " Spawned in the right place already " << endl;
        return c;
    }

    long long cur_t = 2 * c - 1;
    long long pos = c;


    while (cur_t <= t)
    {
        if ((t-cur_t) <= pos)
        {
            return pos - (t-cur_t);
        }

        else {
            //move to front
            cur_t += (pos); //reach 0
            pos = 0;

            cur_t += 1;
            pos = cur_t / 2;

            //cout << "Jumped to time " << cur_t << " at position " << pos << endl;
        }
    }
    return pos;
}

long long findplace(long long p, long long t)
{
    if (t == 0) {
        return p;
    }

    if (p > t/2)
    {
        return p;
    }

    if (p == t/2)
    {
        return findplace(0, t-1);
    }
    else {
        long long DELTA = max((long long) 1, (t - 2 * p) / 3);
        return findplace(p+DELTA, t-DELTA);
    }
    
}
int main() {
    long long Q;
    cin >> Q;

    while (Q--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            cout << findcow(b,c);
        }
        else {
            cout << findplace(b,c);
        }
        cout << endl;
    }
}