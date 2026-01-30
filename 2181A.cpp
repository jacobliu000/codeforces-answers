#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<vector<long long>> words(N, vector<long long>(26, 0));
    vector<long long> total(26, 0);
    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;

        for (char c : a)
        {
            total[c-'A'] += 1;
            words[i][c-'A'] += 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        vector<long long> temp = total;
        long long ans = M+1;

        for (int j = 0; j < 26; j++) {
            vector<long long> goal(26,0);
            temp[j] -= words[i][j];
            goal[j] = temp[j] * M;

            //cout << words[i][j] << " " << temp[j] << endl;
            if (words[i][j] != 0 && temp[j] == 0)
            {
                //cout << " The other words doesnt have any " << (char) ('A' + j) << " so we are skipping" << endl;
                ans = -1;
                break;
            }

            if (words[i][j] == 0)
            {
                //cout << "The word doesnt have " << (char) ('A'+j) << endl;
                continue;
            }

            //binary search

            //find highest K where temp[j] * K < goal[j] - words[i][j]

            long long low = 0;
            long long high = M;
            long long best = -1;
            long long mid;
            
          // cout << (char) ('A'+j) << ": The other words total to " << temp[j] << " total of this letter and since m=" << M << " we have " << goal[j] << " copies and need " << words[i][j] << " in this word " << endl;
            while (low <= high)
            {
                mid = (high + low) / 2;
              //  cout << "Trying " << mid << endl;
                if (temp[j] * mid <= goal[j]-words[i][j])
                {
                    best = mid;
                    low = mid+1;
                   /// cout << " It works, try one higher, so low = " << low << " and high=" << high << endl;
                }
                else {
                    high = mid-1;
          //          cout << " Didn't work, lowering high so low = " << low << " & high = " << high << endl;
                }

                

            }

                ans = min(ans, best);
                //cout << "For the letter " << (char) ('A' + j) << " the best k is at " << best << endl << " since we're given " << goal[j] << " and need to find " << words[i][j] << " and the wordhas " << temp[j] << " of this letter | " << endl;
                

                
        }
   
        cout << ans << " ";
    }
}