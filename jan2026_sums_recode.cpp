#include <iostream>
#include <vector>

using namespace std;


void solve() {

    vector<int> R;
    int N, K;
    cin >> N >> K;

    int min_sol = 0;
    int max_sol = 0;
    int min_sol_ones = 0;
    int max_sol_ones = 0;
    int min_diff = N+1;
    string r_str;
    cin >> r_str;
    for (char c : r_str)
    {
        R.push_back(c-'0');
    }
    //chains
    for (int i = 0; i < K; i++) {
  //      cout << " CHAIN " << i << endl;
        int total_wzeros = 0;
        int total_wones = 1;

        int point_zeros = 0;
        int point_ones = 1;

        for (int j = i; j < N-K; j += K)
        {
            if (R[j] != R[j+1]){
                point_zeros = 1-point_zeros;
                point_ones = 1-point_ones;
            }

     //       cout << " At the point " << j << " we're testing it with " << j + K << " and if the first one was 0, then this one will be " << point_zeros << " and otherwise its " << point_ones << endl;

            total_wzeros += point_zeros;
            total_wones += point_ones;

        }
        if (total_wzeros > total_wones) {
            min_sol += total_wones;
            max_sol += total_wzeros;
            min_sol_ones += 1;
        }
        else {
            min_sol += total_wzeros;
            max_sol += total_wones;
            max_sol_ones += 1;
        }

      //  cout << " Chain that starts at " << i << " could have " << total_wzeros << " if it started with 0, and " << total_wones << " if it started with 1 " << endl;
        min_diff = min(min_diff, abs(total_wones-total_wzeros));

    }

    if (min_sol_ones % 2 != R[0])
    {
        cout << min_sol + min_diff;
    } else 
    {
        cout << min_sol;
    }

    cout << " ";

    if (max_sol_ones % 2 != R[0])
    {
        cout << max_sol - min_diff << endl;
    } else 
    {
        cout << max_sol << endl;
    }



}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}