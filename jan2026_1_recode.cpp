#include <iostream>

using namespace std;

using ll = long long;


ll findcow(ll c, ll t)
{
    if (c == 0 && t == 0) return 0;
    if (t < 2 * c)
    {
        return c;
    }

    ll pos = c - 1;
    ll cur_t = 2 * c;

    while (cur_t < t)
    {
        if (t - cur_t <= pos)
        {
            return pos - (t - cur_t);
        }
        else {
            cur_t += pos;
            cur_t += 1;
            pos = cur_t / 2;
        }
    }

    return pos;

}

ll atpos(ll x, ll t)
{

    if (x > t / 2)
    {
        return x;
    }

    if (x == t / 2) 
    {
        return atpos(0, t-1);
    }
    if (x < t/2)
    {
        ll change = max( (ll ) (t-2*x - 1)/3, (ll) 1);
        return atpos(x+change,t-change);
    }
    //x + F, t - F

    //x + F < (t-F) / 2
    //2x + 2F < t - F
    //3F < t - 2x
    //F < (t - 2x) / 3
    
}

int main() {
    ll Q;

    cin >> Q;

    while (Q--) {
        ll a, b, c;

        cin >> a >> b >> c;

        if (a == 1) cout << findcow(b,c);
        else cout << atpos(b, c);

        cout << endl;
    }
}