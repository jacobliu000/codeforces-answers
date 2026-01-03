#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;

    cin >> T;

    while (T > 0) {
        int N;
        cin >> N;

        vector<int> arr(N,0);
        for (int i = 0; i < N; i++)
        {

            int a;
            cin >> a;            
            arr[i] = a;

        }

        vector<int> pref(N,N+1);
        vector<int> suf(N,0);

        pref[0] = arr[0];
        suf[N-1] = arr[N-1];
        bool ans = true;

        for (int i = 1; i < N; i++)
        {
            pref[i] = min(pref[i-1], arr[i]);
        }

        for (int i = N-2; i>=0; i--)
        {
            suf[i] = max(suf[i+1], arr[i]);
        }
/*
        for (int p : pref)
        {
            cout << p << " ";
        }
        cout << endl;

        for (int s : suf)
        {
            cout << s << " ";
        }
        cout << endl;
*/
        for (int i = 1; i < N; i++)
        {
            if (pref[i-1] > suf[i])
            {
                ans = false;
            }
        }

        if (ans) {cout << "Yes";} else {cout<<"No";}
        cout << endl;
        T--;
    }
}