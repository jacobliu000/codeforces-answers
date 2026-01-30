#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T>0) {
        T--;
        string ans = "Yes";
        int n;
        cin >> n;
        if (n == 0) {
            ans = "Yes";
            cout << ans << endl;
            continue;
        }



        string bin = bitset<30>(n).to_string();

        int start = 0;
        int end = bin.length() - 1;

        while (bin[start] == '0')
        {start+=1;}

        while (bin[end] == '0')
        {end-=1;}

        bin = bin.substr(start, end-start+1);

        if (bin.length() % 2 == 1 && bin[bin.length() / 2] == '1')
        {
         //   cout << " MIDDLE CHARACTER DOESNT WORK ";
            ans = "No";
        }

        for (int i = 0; i < bin.length(); i++)
        {
            if (bin[i] != bin[bin.length() - 1 - i]) {
               // cout << " NOT REVERSABLE " << bin << " ";
                ans = " No";
            }
        }

        cout << ans << endl;

    }
}