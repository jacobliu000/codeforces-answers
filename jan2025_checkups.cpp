#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
using ll = long long;

ll ways2(ll n) {
    return n * (n+1) / 2;
}
int main() {
    ll N;
    cin >> N; 
    vector<ll> A, B;
    //get a and b
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        x--;
        A.push_back(x);
    }

    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        x--;
        B.push_back(x);
    }
    vector<vector<pair<ll, ll>>> species(N); // 0 = A, 1 = B
    ll ans = 0;

    for (ll i = 0; i < N; i++)
    {
        ll a = A[i];
        ll b = B[i];

        species[a].push_back({i, 0});
        species[b].push_back({i, 1});

  //      cout << " POS " << i << " adding " << a << " and " << b << endl;
 
        if (a == b) {
            ans += ways2(i) + ways2(N-1-i);
        }
    }



    for (int s = 0; s < N; s++) {
        //s is the SPECIES
      //  cout << "Visiting species " << s + 1 << endl;
        vector<pair<ll, ll>> specie = species[s];
        for (int j = 0; j < 2; j++) {
            ll add = 0;
          //  cout << " LOOP " << j << endl;
            stack<ll> rights;
            ll lefts = 0;
            ll sum_right = 0;
            ll sum_left = 0;

            for (ll i = specie.size()-1; i >= 0; i--) {
                
                pair<ll, ll> cur = specie[i];

                if (cur.second == 1) {
                    rights.push(N - cur.first);
                    sum_right += N-cur.first;
                 //   cout << " At " << cur.first << " which is a B " << endl;
                //    cout << " At pos " << cur.first << " and its in array B so we added " << (N-cur.first) << " to sum_rights which is now " << sum_right << endl;
                }
                else {
                 //   cout << " At pos " << cur.first << " (which is in array A) " << endl;
                    while (!rights.empty() && rights.top() > (cur.first + 1))
                    {
                       // cout << "- Popping " << rights.top() << " and adding 1 to lefts" << endl;
                        sum_right -= rights.top();
                        rights.pop();
                        
                        lefts += 1;

                    }

                    sum_left = lefts * (cur.first + 1);

                    //cout << "At " << cur.first << " Sum left " << sum_left << " | Sum right " << sum_right << endl;
                    ans += sum_left;
                    ans += sum_right;
                    add += sum_left;
                    add += sum_right;
                   // cout << " ans = " << ans << endl;
                }
            }
            
            for (ll z = 0; z < specie.size(); z++) {
                specie[z].first = N - 1 - specie[z].first;
            }
            reverse(specie.begin(), specie.end());

       //     cout << " FOR SPECIES " << s + 1 << " LOOP # " << j << " I GOT " << add << endl;
    
        }
        
    }
    cout << ans;
}