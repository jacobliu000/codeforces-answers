//incomplete

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T>0){
        int N;
        cin >> N;
        vector<int> odds;
        vector<int> evens;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            if (a%2==0)
            {
                evens.push_back(a);
            }
            else {
                odds.push_back(a);
            }
        }
        sort(evens.begin(), evens.end(), std::greater<int>());
        sort(odds.begin(), odds.end(), std::greater<int>());
        if (odds.size() == 0)
        {
            for (int i = 0; i < N; i++)
            {
                cout << 0 << " ";
            }
            cout << endl;
        }
        else if (evens.size() == 0)
        {
            for (int i = 0; i < N; i++)
            {
                if (i % 2 == 0)
                {
                    cout << odds[0] << " ";
                }else {
                    cout << 0 << " ";
                }
            }
        }
        else {
            //O, OE, OEE, OEEE..

            int m = evens.size();
            int s = odds[0];

            cout << s << " ";

            for (int i = 0; i < m; i++)
            {
                s += evens[i];
                cout << s << " ";
                
            }

            int odd_size = odds.size();
            int odds_used;
            if (odd_size == 2)
            {
                cout << 0;
                T--;
                cout << endl;
                continue;
            }
            for (int i = 0; i < N-m-1; i++)
            {
               if (i % 2 == 0 && odds_used )
               {
                cout << s - evens[m-1] << " ";
               }
               else {
                cout << s << " ";
                odds_used += 2;
                if (odds_used > odds.size())
                {
                    if (odds.size() % 2 == 0)
                    {
                    cout << 0 << " ";
                    }
                    break;
                }
               }
            }

            cout << endl;
            }

    

        T--;
}
    }
