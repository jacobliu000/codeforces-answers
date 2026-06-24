#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
//        cout << " start " << endl;
        int n, k; cin >> n >> k;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            nums.push_back(x);
        }
        
        sort(nums.begin(), nums.end());
        //find all groups
        int groups_count = 0;
        int cur_group_size = 1;
        int cur_num = nums[0];
        bool all_odd = true;

        vector<int> groups;
        for (int i = 1; i < n; i++) {
            if (nums[i] == cur_num) {
                cur_group_size += 1;
            } else {
                //cout << " Found new group at i=" << i << endl;
                groups.push_back(cur_num);
                groups_count += 1;
                cur_num = nums[i];
                if (cur_group_size % 2 == 0) all_odd = false;
                cur_group_size = 1;
            }
        }
        groups_count += 1;
        groups.push_back(cur_num);

        if (cur_group_size % 2 == 0) {
            cout << "YES";// - max group size even";
        } else {
            if (groups_count == 1) 
            {
                cout << "NO";// - max group size odd, no second max";
            }
            else {
                if (groups[groups_count - 1] - groups[groups_count - 2] <= k) {
                    cout << "YES";// - max group size odd, is second max within k";
                }
                else {
                    if (all_odd) {
                        bool separated = true;
                        for (int i = 1; i < groups_count; i++) {
                            if (groups[i] - groups[i-1] <= k) 
                            {
                                separated = false;
                            }
                        }

                        if (separated) cout << "NO";// - max group size odd, everything is separated and odd";
                        else cout << "YES";// - max group size odd, everything is odd but theres something not separated";
                    }
                    else {
                        cout << "YES";// - max group size odd but not everythings odd";
                    }
                }

            }
        }
        
        cout << endl;
    }
}