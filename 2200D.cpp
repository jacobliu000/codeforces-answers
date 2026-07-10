#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> arr(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int min_middle_val = n+1;
        int min_middle_loc = -1;
        //get middle section
        for (int i = x; i < y; i++) {
            if (arr[i] < min_middle_val) {
                min_middle_val = arr[i];
                min_middle_loc = i;
            }
        }

  //    cout << " min middle: " << min_middle_val << endl;

        vector<int> ans;

        vector<int> middle;
        for (int i = min_middle_loc; i < y; i++) {
            middle.push_back(arr[i]);
        }
        for (int i = x; i < min_middle_loc; i++) {
            middle.push_back(arr[i]);
        }

        vector<int> outside;
        for (int i = 0; i < x; i++) {
            outside.push_back(arr[i]);
        }
        for (int i = y; i < n; i++) {
            outside.push_back(arr[i]);
        }


        if (outside.size() == 0 || min_middle_val <= outside[0]) {
            ans.insert(ans.end(), middle.begin(), middle.end());
            ans.insert(ans.end(), outside.begin(), outside.end());
        }
        else {
            int min_outside_val = outside[outside.size()-1];
            int min_outside_loc = outside.size()-1;

            for (int i = 0; i < outside.size() - 1; i++) {
                if (outside[i+1] > min_middle_val) {
                    min_outside_val = outside[i];
                    min_outside_loc = i;
                    break;
                }
            }

            if (outside.size() != 0) {
                ans.insert(ans.end(), outside.begin(), outside.begin() + min_outside_loc + 1);
                ans.insert(ans.end(), middle.begin(), middle.end());
                ans.insert(ans.end(), outside.begin() + min_outside_loc + 1, outside.end());
            }
            else {
                ans.insert(ans.end(), middle.begin(), middle.end());
            }


        }



        for (int a : ans) {
            cout << a << " ";
        }
        cout << endl;
        
    }
}
