#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;



int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> depth(n+1, 1);

        vector<vector<int>> children(n+1, vector<int>());
        vector<int> parent(n+1, -1);
        for (int i = 2; i <= n; i++) {
            int a; cin >> a;
            children[a].push_back(i);
            parent[i] = a;

        }

        stack<int> st;
        vector<int> order;
        st.push(1);

        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            order.push_back(cur);

            for (int c : children[cur]) {
                st.push(c);
            }

        }

        reverse(order.begin(), order.end());

        for (int v : order) {
            if (children[v].size()==0) continue;
            int curdepth = -1;
            for (int c : children[v]) {
                curdepth = max(curdepth, depth[c]); 
            }
            depth[v] = curdepth + 1;
        }

        vector<int> ans(n+1,0);
        for (int v : order) {
            

            if (children[v].size() == 0) ans[v] = 1;
            else if (children[v].size() == 1) {
                ans[v] = 1 + ans[children[v][0]];
            }
            else {
                sort(children[v].begin(), children[v].end());
                int first_max = -1;
                int second_max = -1;
                int sum_ans = 0;
                for (int c : children[v]) {
                    sum_ans += ans[c];
                    int dep = depth[c];
                    if (dep > first_max) {
                        second_max = first_max;
                        first_max = dep;
                    }
                    else if (dep > second_max && dep <= first_max) {
                        second_max = dep;
                    }
                }

                ans[v] = 1 + second_max + sum_ans;
            }
        }

        cout << ans[1] << endl;
    }
}