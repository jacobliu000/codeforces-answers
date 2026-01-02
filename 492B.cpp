#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;

    cin >> n >> l;

    vector<long double> street(n,-1);
    for (int i = 0; i < n; i++)
    {
        long double a;
        cin >> a;
        street[i] = a;
    }


    sort(street.begin(), street.end());

    long double gap = -1;
    if (n==2)
    {

        gap = max((street[1]-street[0])/2,gap);   
     }
    for (int i = 0; i < n; i++)
    {
        if (i == 0) {
            gap = max(gap, street[i]);
        }
        if (i == n-1)
        {
            gap = max(gap, l-street[i]);
        }
        else {

        gap = max((street[i+1]-street[i])/2,gap);
cout << fixed;


        }
    }

    cout << gap;
}