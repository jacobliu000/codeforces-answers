#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;

        cin >> N >> K;

        string R;

        cin >> R;

        vector<int> nums;
        for (char c : R)
        {
            nums.push_back(c-'0');
        }




        int sol1 = 0;
        int sol2 = 0;

        int mindiff = N+1;

        int parity1 = 0;
        int parity2 = 0;

        //for each chain
        for (int i = 0; i < K; i++)
        {
            int first0 = 0;
            int first1 = 1;

            int first0_cnt = first0;
            int first1_cnt = first1;

            int chain = nums[i];
            for (int j = i; j+K < N; j += K)
            {
                //nums[j] XOR nums[j+1]
                int change = nums[j] ^ nums[j+1];


               //cout << j << " is " << nums[j] << " | " << j + 1 << " is " << nums[j+1] << endl;
                first0 ^= change;
                first1 ^= change;


                first0_cnt += first0;
                first1_cnt += first1;

             //  cout << "Just checked indexes " << j << " " << j + 1 << endl;
            }

           // cout << " GROUP " << i << " can have " << first0_cnt << " 1s if it starts with 0, and " << first1_cnt << " 1s if it starts with 1 ";
            mindiff = min(mindiff, max(first1_cnt-first0_cnt, first0_cnt-first1_cnt));

            int add1, add2; //the thing added

            if (first0_cnt < first1_cnt)
            {
                sol1 += first0_cnt;
                sol2 += first1_cnt;

                add1 = 0;
                add2 = 1;
            }

            else {
                sol1 += first1_cnt;
                sol2 += first0_cnt;

                add1 = 1;
                add2 = 0;
            }

            parity1 += add1;
            parity2 += add2;

           // cout << parity1 << " " << parity2;


        }

        if (parity1 % 2 == nums[0])
        {
            cout << sol1 << " ";
        }
        else {
           cout << sol1 + mindiff << " ";
        }

        if (parity2 % 2 == nums[0])
        {
            //cout << " FIRST " << K << " in max solution has wrong number, so added " << mindiff

            cout << sol2;
        }
        else {
            cout << sol2 - mindiff;
        }

        cout << endl;


    }
}