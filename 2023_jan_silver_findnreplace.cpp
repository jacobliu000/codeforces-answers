#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
     //   cout << 'z' - 'A' << endl;
      //  cout << 'a' - 'A' << endl;
       string initial;
       string target;
       cin >> initial >> target;

       bool is_possible = true;
       int chars_used = 0;
       //intial.size() == target.size()

        vector<int> edge(58, -1);
        vector<int> inedge(58, 0);
        vector<bool> vst(58, false);
        for (int i = 0; i < initial.size(); i++) {
            int init = initial[i] - 'A';
            int targ = target[i] - 'A';

            if (inedge[targ] == 0) {
                chars_used += 1;
            }

            if (edge[init] == -1) {
                edge[init] = targ;
                inedge[targ] += 1;

             //   cout << " edge [" << init << "] = " << targ << endl;
                //cout << " assigning edge[" << init << "] to " << targ << endl;
            } else {
                if (edge[init] != targ) {
                // cout << " Found a double count at " << init << " so its not possible " << endl;
                    is_possible = false;
                    break;
                }
            }

       }

        int ans = 0;
    
        if (!is_possible) {
            cout << -1;
        }
        else {
            //find total number of edges that arent directed into self
            for (int i = 0; i < edge.size(); i++) {
                if (edge[i] != i && edge[i] != -1) {
                    ans += 1;
                }
            }

            
            for (int i = 0; i < edge.size(); i++) {
                if (vst[i] == true) continue;

                vst[i] = true;
                int cur = i;
                int loopsize = 1;
                bool is_loop = true;

                while (edge[cur] != -1 && vst[edge[cur]] == false) {
                 //   cout << " in edge of " << cur << " is " << inedge[cur] << endl;

                    if (inedge[cur] != 1) is_loop = false;
                    vst[cur] = true;
                    cur = edge[cur];
                    loopsize += 1;

                }

                if (loopsize > 1 && is_loop && edge[cur] != -1 && edge[cur] == i && inedge[cur] == 1) {
                    if (chars_used >= 52) {
                        ans = -1;
                        break;
                    }
                    ans += 1;

                  //cout << " found a loop so ans += 1" << endl;
                }
            }

            cout << ans;
        }


        cout << "\n";
        
    }
}