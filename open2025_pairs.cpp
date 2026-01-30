#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
int main() {
    ll N, A, B;

    ll sol = 0;
    cin >> N >> A >> B;

    map<ll, ll> cows;
    map<ll, set<ll>> edges;
    queue<ll> leaves;
    set<ll> vst;

    for (ll i = 0; i < N; i++) {
        ll d, n;
        cin >> d >> n;
        cows[n] = d;
    }


    //create edges
    for (auto [x, _] : cows)
    {
       // leaves.push(x);

        edges[x] = {};
       // cout << " CHECKING " << x << endl;
        if (cows.count(A-x))
        {
         //   cout << " We can do " << A - x << endl;
            edges[x].insert(A-x);
        }

        if (cows.count(B-x)) {
            edges[x].insert(B-x);

        }

        if (edges[x].size() == 1) {leaves.push(x);}

        
    }

    /*
        for (int x : IDs) {
            cout << x << " : ";
            for (int j : edges[x]) {
                cout << j << " ";
            }
            cout << endl;
        }*/

        //leaf peeling time
    
        int counter = 10;

    

    while (!leaves.empty())
    {
        

        ll cur = leaves.front();
        leaves.pop();
        if (edges[cur].size() != 1) continue;
        ll x = *edges[cur].begin();

        //peel it!!!

        //cout << " visiting " << cur << " which is a leaf, and checking its relations with " << x << endl;

        if (x != cur) {
            ll rm = min(cows[x], cows[cur]);

         //  cout << " Can remove up to " << rm << " since I have " << cows[cur] << " and they have " << cows[x] << endl;
            cows[x] -= rm;
            cows[cur] -= rm;

            sol += rm;

        }
        else {
            
            ll rm = cows[cur]/2;
            sol += rm;
            cows[cur] -= rm * 2;

        }


        //if (cows[cur] == 0)
        //{
        edges[cur].erase(x);
        edges[x].erase(cur);

       // cout << x << " now only has " << edges[x].size() << " edges left in it, since " << cur << " was erased form the list " << endl;
        
        leaves.push(x);



         // cout << "-  which lead to " << rm << " new relations " << endl;
        //}

    }

    cout << sol;
    }